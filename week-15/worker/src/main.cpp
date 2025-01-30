#include "../include/password_cracker.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main() {
    int client_socket;
    const char* SERVER_IP = "192.168.1.1";
    const int PORT = 8080;
    int numThreads = 0;
    atomic<bool> found(false);
    atomic<bool> password_found(false);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        cerr << "Не удалось создать сокет!" << endl;
        return -1;
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        cerr << "Не удалось подключиться к серверу!" << endl;
        close(client_socket);
        return -1;
    }

    char buffer[1024];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received <= 0) {
        cerr << "Сервер отключен!" << endl;
        close(client_socket);
        return -1;
    }
    buffer[bytes_received] = '\0';
    string message = buffer;
    stringstream ss(message);
    string targetMD5String;
    int len;
    ss >> targetMD5String >> len;

    numThreads = thread::hardware_concurrency();
    if (numThreads == 0) {
        numThreads = 4;
    }
    cout << "Воркер использует " << numThreads << " потоков." << endl;

    while (!found.load() && !password_found.load()) {
        bruteForceMD5(targetMD5String, numThreads, len, client_socket, ref(found), ref(password_found));
        if (!found.load() && !password_found.load()) {
            string not_found = "not found";
            send(client_socket, not_found.c_str(), not_found.length(), 0);

            bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
            if (bytes_received <= 0) {
                close(client_socket);
                cout << "воркер завершил работу" << endl;
                break;
            }
            buffer[bytes_received] = '\0';
            message = buffer;
            if (message == "Пароль найден всем спасибо") {
                found.store(true);
                close(client_socket);
                cout << "воркер завершил работу" << endl;
                break;
            } else if (message == "close") {
                close(client_socket);
                cout << "воркер завершил работу" << endl;
                break;
            } else {
                stringstream ss(message);
                ss >> targetMD5String >> len;
            }
        }
    }

    bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        string close_message = buffer;
        if (close_message == "close") {
            close(client_socket);
            cout << "воркер завершил работу" << endl;
        }
    } else if (bytes_received == 0) {
        close(client_socket);
        cout << "воркер завершил работу" << endl;
    }
    return 0;
}

