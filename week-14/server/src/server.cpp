#include "../include/server.hpp"
#include "../include/function.hpp"
#include <cstring>
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

Server::Server() {
    opt = 1;
    addrlen = sizeof(address);
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        cerr << "Ошибка при создании сокета" << endl;
        exit(EXIT_FAILURE);
    }

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        cerr << "Ошибка при привязке сокета" << endl;
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        cerr << "Ошибка при прослушивании" << endl;
        exit(EXIT_FAILURE);
    }
}

void Server::start() {
    cout << "Сервер запущен на порту " << PORT << endl;
    
    while (true) {
        int client_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        if (client_socket < 0) {
            cerr << "Ошибка при подключении клиента" << endl;
            continue;
        }

        cout << "Новый клиент подключен" << endl;

        std::thread client_thread([this, client_socket]() {
            handleClient(client_socket);
        });
        client_thread.detach(); 
    }
}

void Server::addClient(int client_socket) {
    std::lock_guard<std::mutex> guard(mtx);
    client_sockets.push_back(client_socket);
}

void Server::removeClient(int client_socket) {
    std::lock_guard<std::mutex> guard(mtx);
    client_sockets.erase(std::remove(client_sockets.begin(), client_sockets.end(), client_socket), client_sockets.end());
}

void Server::handleClientDisconnection(int client_socket) {
    removeClient(client_socket);
    std::cout << "Клиент отключен: " << client_socket << std::endl;
}

void Server::handleClient(int client_socket) {
    addClient(client_socket);
    char buffer[1024] = {0};

    while (true) {
        int bytes_read = read(client_socket, buffer, sizeof(buffer));
        if (bytes_read <= 0) {
            handleClientDisconnection(client_socket);
            close(client_socket);
            return;
        }

        std::string message(buffer, bytes_read);
        broadcastMessage(message);
        memset(buffer, 0, sizeof(buffer)); 
    }
}

void Server::broadcastMessage(const std::string& message) {
    std::lock_guard<std::mutex> guard(mtx);
    for (int socket : client_sockets) {
        send(socket, message.c_str(), message.length(), 0);
    }
}



