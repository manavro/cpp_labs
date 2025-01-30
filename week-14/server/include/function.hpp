#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <string>

void addClient(int client_socket);
void removeClient(int client_socket);
void sendMessageToClient(int client_socket, const std::string& message);
void handleClientDisconnection(int client_socket);
void handleClient(int client_socket);
void broadcastMessage(const std::string& message); 

#endif 



