#include "password.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

PasswordCracker::PasswordCracker(const string& targetHash, int passwordLength)
    : targetHash(targetHash), passwordLength(passwordLength) {}

string PasswordCracker::md5(const string& str) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)str.c_str(), str.size(), digest);
    
    ostringstream oss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
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

void PasswordCracker::crack() {
    const int numThreads = thread::hardware_concurrency();
    vector<thread> threads;

    int range = 1000000 / numThreads; 

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(&PasswordCracker::generatePasswords, this, i * range, (i + 1) * range);
    }

    for (auto& thread : threads) {
        thread.join();
    }
}






