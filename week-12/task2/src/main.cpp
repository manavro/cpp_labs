#include <iostream>
#include "password.hpp"
#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>

using namespace std;

int main(int argc, char* argv[]) {
    plog::init(plog::debug, "log.txt", 1024 * 1024, 3); 

    if (argc < 4) {
        cerr << "Использование: " << argv[0] << " <target_hash> <password_length> <num_threads>" << endl;
        return 1;
    }

    string targetHash = argv[1];
    int passwordLength = stoi(argv[2]);
    int numThreads = stoi(argv[3]);

    PasswordCracker cracker(targetHash, passwordLength, numThreads);
    cracker.crack(); 

    return 0;
}




