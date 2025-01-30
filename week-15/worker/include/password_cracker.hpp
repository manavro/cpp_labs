#ifndef PASSWORD_CRACKER_HPP
#define PASSWORD_CRACKER_HPP

#include <iostream>
#include <string>
#include <thread>
#include <atomic>
#include <vector>
#include <arpa/inet.h>
#include <openssl/evp.h>
#include <sstream>

using namespace std; 


#define MD5_DIGEST_LENGTH 16

extern unsigned char targetMD5[MD5_DIGEST_LENGTH];

void computeMD5FromString(const string &str, unsigned char *result);
string md5ToString(unsigned char *md);
void bruteForceMD5Thread(int threadId, const string &targetMD5, const string &chars, int len, long long startIdx, long long endIdx, int client_socket, atomic<bool> &found, atomic<bool> &password_found);
void bruteForceMD5(const string &targetMD5, int numThreads, int len, int client_socket, atomic<bool> &found, atomic<bool> &password_found);

#endif 


