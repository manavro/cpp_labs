#include "../include/server.hpp"


int server_socket_global = -1;
vector<int> clients_global;
mutex clients_mutex_global;
atomic<bool> server_running(true);
vector<string> message_history;
mutex history_mutex;
unsigned char targetMD5[MD5_DIGEST_LENGTH];

void computeMD5FromString(const string &str, unsigned char *result) {
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, EVP_md5(), NULL);
    EVP_DigestUpdate(mdctx, str.c_str(), str.length());
    EVP_DigestFinal_ex(mdctx, result, NULL);
    EVP_MD_CTX_free(mdctx);
}

string md5ToString(unsigned char *md) {
    stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)md[i];
    }
    return ss.str();
}

void create_socket(int& socket_fd) {
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        throw runtime_error("Не удалось создать сокет!");
    }
}

void bind_socket(int socket_fd, sockaddr_in& server_addr) {
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        throw runtime_error("Не удалось привязать сокет!");
    }
}

void listen_socket(int socket_fd) {
    if (listen(socket_fd, 5) == -1) {
        throw runtime_error("Не удалось начать прослушивание!");
    }
}

void signalHandler(int signum) {
    if (signum == SIGINT) {
        cout << "Сервер получил сигнал SIGINT (Ctrl+C). Завершаем работу..." << endl;
        server_running = false;

        
        if (server_socket_global != -1) {
            close(server_socket_global);
        }
        {
            lock_guard<mutex> guard(clients_mutex_global);
            for (int client_socket : clients_global) {
                close(client_socket);
            }
        }

        
        system("pkill -f worker");
        
        cout << "Сервер завершил работу." << endl;
        exit(0); 
    }
}

