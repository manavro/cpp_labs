#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <vector>
#include <mutex>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <unistd.h> 
#include <algorithm> 

#define PORT 8080
#define MAX_CLIENTS 10

class Server {
public:
    Server();
    void start();

private:
    void addClient(int client_socket); 
    void removeClient(int client_socket);
    void sendMessageToClient(int client_socket, const std::string& message);
    void handleClientDisconnection(int client_socket); 
    void handleClient(int client_socket);
    void broadcastMessage(const std::string& message); 

    int server_fd;
    int opt;
    struct sockaddr_in address;
    int addrlen;
    std::vector<int> client_sockets;
    std::mutex mtx;
};

#endif 





