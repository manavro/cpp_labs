#include "../include/password_cracker.hpp"
#include <iomanip> 
#include <cmath>   
#include <sstream> 
#include <atomic>  
#include <thread>  
#include <iostream> 
#include <openssl/evp.h> 

using namespace std;

unsigned char targetMD5[MD5_DIGEST_LENGTH];
atomic<bool> found(false);
atomic<bool> password_found(false);

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

void bruteForceMD5Thread(int threadId, const string &targetMD5, const string &chars, int len, long long startIdx, long long endIdx, int client_socket, atomic<bool> &found, atomic<bool> &password_found) {
    unsigned char result[MD5_DIGEST_LENGTH];

    for (long long index = startIdx; index < endIdx; ++index) {
        if (found.load() || password_found.load()) {
            return;
        }

        string currentStr;
        long long tempIndex = index;
        for (int i = 0; i < len; i++) {
            currentStr = chars[tempIndex % chars.size()] + currentStr;
            tempIndex /= chars.size();
        }

        computeMD5FromString(currentStr, result);
        string computedMD5 = md5ToString(result);
        if (computedMD5 == targetMD5) {
            password_found.store(true);
            cout << "Thread " << threadId << ": Found password: " << currentStr << endl;
            send(client_socket, currentStr.c_str(), currentStr.length(), 0);
            return;
        }
    }
}

void bruteForceMD5(const string &targetMD5, int numThreads, int len, int client_socket, atomic<bool> &found, atomic<bool> &password_found) {
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    vector<thread> threads;
    long long totalCombinations = pow(chars.size(), len);
    long long chunkSize = totalCombinations / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        long long startIdx = i * chunkSize;
        long long endIdx = (i == numThreads - 1) ? totalCombinations : startIdx + chunkSize;
        threads.push_back(thread(bruteForceMD5Thread, i, ref(targetMD5), ref(chars), len, startIdx, endIdx, client_socket, ref(found), ref(password_found)));
    }

    for (auto &t : threads) {
        t.join();
    }
}


