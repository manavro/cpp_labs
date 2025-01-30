#ifndef PASSWORD_HPP
#define PASSWORD_HPP

#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <openssl/md5.h>
#include <plog/Log.h>

using namespace std;

class PasswordCracker {
public:
    PasswordCracker(const string& targetHash, int passwordLength);
    void crack();
    
private:
    void generatePasswords(int start, int end);
    string md5(const string& str);
    
    string targetHash;
    int passwordLength;
    mutex mtx;
};

#endif









