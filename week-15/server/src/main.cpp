#include "../include/server.hpp"

int main() {
    int server_socket, client_socket;
    sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    const int PORT = 8080;
    const int MAX_PASSWORD_LENGTH = 8; 
    vector<int> clients;
    vector<thread> workerThreads;
    mutex clients_mutex;
    atomic<bool> found(false);
    string found_password;
    string password;
    queue<int> availableLengths;

    for (int i = 1; i <= MAX_PASSWORD_LENGTH; ++i) {
        availableLengths.push(i);
    }

    
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = signalHandler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);

    try {
        cout << "Введите пароль: ";
        cin >> password;

        create_socket(server_socket);
        server_socket_global = server_socket;

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(PORT);
        server_addr.sin_addr.s_addr = INADDR_ANY;

        bind_socket(server_socket, server_addr);
        listen_socket(server_socket);

        cout << "Сервер запущен, ожидаем подключения воркеров..." << endl;

        computeMD5FromString(password, targetMD5);
        string targetMD5String = md5ToString(targetMD5);

        int worker_count = 0;
        while (worker_count < 5 && server_running.load()) {
            client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
            if (client_socket == -1) {
                if (worker_count > 0) {
                    break;
                } else {
                    throw runtime_error("Ошибка при принятии подключения!");
                }
            }

            {
                lock_guard<mutex> guard(clients_mutex);
                clients_global.push_back(client_socket);
                clients.push_back(client_socket);
            }

            int currentLength = 0;
            if (!availableLengths.empty()) {
                currentLength = availableLengths.front();
                availableLengths.pop();
            } else {
                string close_message = "close";
                send(client_socket, close_message.c_str(), close_message.length(), 0);
                close(client_socket);
                continue;
            }

            
            string message = targetMD5String + " " + to_string(currentLength);
            send(client_socket, message.c_str(), message.length(), 0);

            cout << "Worker " << worker_count + 1 << " подключен. Длина:" << currentLength << endl;

            workerThreads.push_back(thread([client_socket, &found, &found_password, &clients, &clients_mutex, &availableLengths, targetMD5String, worker_count]() {
                char buffer[1024];
                while (true) {
                    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
                    if (bytes_received <= 0) {
                        break;
                    }
                    buffer[bytes_received] = '\0';
                    string message = buffer;
                    if (message == "not found") {
                        int currentLength = 0;
                        if (!availableLengths.empty()) {
                            currentLength = availableLengths.front();
                            availableLengths.pop();
                        } else {
                            string close_message = "close";
                            send(client_socket, close_message.c_str(), close_message.length(), 0);
                            close(client_socket);
                            break;
                        }

                        
                        if (currentLength > MAX_PASSWORD_LENGTH) {
                            string close_message = "close";
                            send(client_socket, close_message.c_str(), close_message.length(), 0);
                            close(client_socket);
                            break;
                        }

                        message = targetMD5String + " " + to_string(currentLength);
                        send(client_socket, message.c_str(), message.length(), 0);
                        cout << "Воркер " << worker_count + 1 << " запросил следующую длину, выдаю:" << currentLength << endl;
                    } else if (message != "close" && message != "not found" && !message.empty()) {
                        found.store(true);
                        found_password = message;
                        cout << "Пароль найден: " << found_password << endl;

                        {
                            lock_guard<mutex> guard(clients_mutex);
                            for (int client_socket : clients) {
                                string found_message = "Пароль найден всем спасибо";
                                send(client_socket, found_message.c_str(), found_message.length(), 0);
                            }
                        }
                        break;
                    } else if (message == "close") {
                        close(client_socket);
                        break;
                    }
                }
            }));
            worker_count++;
        }

        while (!found.load() && server_running.load()) {
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        {
            lock_guard<mutex> guard(clients_mutex);
            for (int client_socket : clients) {
                close(client_socket);
            }
            clients.clear();
        }

        close(server_socket);
        cout << "Сервер завершает работу" << endl;
    } catch (const runtime_error& e) {
        cerr << "Ошибка: " << e.what() << endl;
        if (server_socket != -1) {
            close(server_socket);
        }
        return -1;
    }

    return 0;
}

