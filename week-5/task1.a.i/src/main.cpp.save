#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter file name: ";
    std::getline(std::cin, filename);

    std::ifstream file(filename);

    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "'." << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    if (file.bad()) {
        std::cerr << "Error: An error occurred while reading the file." << std::endl;
        return 1;
    }

    file.close();
    return 0;
}
