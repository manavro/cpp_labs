#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <vector>
#include <mutex>
#include <stdexcept>
#include <openssl/evp.h>
#include <iomanip>
#include <sstream>
#include <atomic>
#include <queue>
#include <csignal>
#include <cstdlib>
#include <algorithm>


using namespace std;


extern vector<string> message_history;
extern mutex history_mutex;

#define MD5_DIGEST_LENGTH 16
extern unsigned char targetMD5[MD5_DIGEST_LENGTH];


extern int server_socket_global;
extern vector<int> clients_global;
extern atomic<bool> server_running;


void computeMD5FromString(const string &str, unsigned char *result);
string md5ToString(unsigned char *md);
void create_socket(int& socket_fd);
void bind_socket(int socket_fd, sockaddr_in& server_addr);
void listen_socket(int socket_fd);
void signalHandler(int signum);

#endif 

