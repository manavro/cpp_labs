#include <iostream>
#include "password.hpp"
#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>

using namespace std;

int main(int argc, char* argv[]) {
    plog::init(plog::debug, "log.txt", 1024 * 1024, 3); 

    if (argc < 3) {
        cerr << "Использование: " << argv[0] << " <target_hash> <password_length>" << endl;
        return 1;
    }

    string targetHash = argv[1];
    int passwordLength = stoi(argv[2]);

    PasswordCracker cracker(targetHash, passwordLength);
    cracker.crack();

    return 0;
}



