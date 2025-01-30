#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <cstring> 

using namespace std; 

#define PORT 8080

void receiveMessages(int sock) {
    char buffer[1024] = {0};
    while (true) {
        int bytes_read = read(sock, buffer, sizeof(buffer));
        if (bytes_read > 0) {
            cout << "Сообщение: " << string(buffer, bytes_read) << endl;
        }
        memset(buffer, 0, sizeof(buffer)); 
    }
}

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cout << "Ошибка создания сокета" << endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        cout << "Неверный адрес" << endl;
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        cout << "Ошибка подключения" << endl;
        return -1;
    }

    thread receiver(receiveMessages, sock);
    receiver.detach();

    string message;
    while (true) {
        getline(cin, message);
        send(sock, message.c_str(), message.length(), 0);
    }

    return 0;
}




