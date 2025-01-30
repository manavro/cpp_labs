#include "../include/function.hpp"
#include "../include/server.hpp"
#include <iostream>
#include <vector>
#include <mutex>
#include <cstring>
#include <unistd.h>
#include <algorithm> 

std::vector<int> client_sockets; 
std::mutex mtx; 

void addClient(int client_socket) {
    std::lock_guard<std::mutex> guard(mtx);
    client_sockets.push_back(client_socket);
}

void removeClient(int client_socket) {
    std::lock_guard<std::mutex> guard(mtx);
    client_sockets.erase(std::remove(client_sockets.begin(), client_sockets.end(), client_socket), client_sockets.end());
}

void sendMessageToClient(int client_socket, const std::string& message) {
    send(client_socket, message.c_str(), message.length(), 0);
}

void handleClientDisconnection(int client_socket) {
    removeClient(client_socket);
    std::cout << "Клиент отключен: " << client_socket << std::endl;
}

void handleClient(int client_socket) {
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

void broadcastMessage(const std::string& message) {
    std::lock_guard<std::mutex> guard(mtx);
    for (int socket : client_sockets) {
        send(socket, message.c_str(), message.length(), 0);
    }
}




