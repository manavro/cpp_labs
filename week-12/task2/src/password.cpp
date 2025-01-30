#include "password.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <openssl/evp.h> 

using namespace std;

PasswordCracker::PasswordCracker(const string& targetHash, int passwordLength, int numThreads)
    : targetHash(targetHash), passwordLength(passwordLength), numThreads(numThreads) {}

string PasswordCracker::md5(const string& str) {
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digestLength;

    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_md5(), NULL);
    EVP_DigestUpdate(ctx, str.c_str(), str.size());
    EVP_DigestFinal_ex(ctx, digest, &digestLength);
    EVP_MD_CTX_free(ctx);

    ostringstream oss;
    for (unsigned int i = 0; i < digestLength; ++i) {
        oss << hex << setw(2) << setfill('0') << (int)digest[i];
    }
    return oss.str();
}

void PasswordCracker::generatePasswords(int start, int end) {
    for (int i = start; i < end; ++i) {
        string password = to_string(i); 
        if (md5(password) == targetHash) {
            lock_guard<mutex> guard(mtx);
            cout << "Пароль найден: " << password << endl;
            return;
        }
        
        if (i % 10000 == 0) { 
            cout << "Проверка пароля: " << password << endl;
        }
    }
}

double PasswordCracker::crack() {
    auto startTime = chrono::high_resolution_clock::now();

    vector<thread> threads;
    int range = 1000000 / numThreads; 

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(&PasswordCracker::generatePasswords, this, i * range, (i + 1) * range);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = endTime - startTime;

    cout << "Время выполнения: " << duration.count() << " секунд." << endl;
    return duration.count();
}




