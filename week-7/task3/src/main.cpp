#include "search.hpp"
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string directory;
    std::cout << "Enter the path to the search directory: ";
    std::getline(std::cin, directory);

    int choice;
    std::cout << "Select to search by (1) file name or (2) file content: ";
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
        std::string filename;
        std::cout << "Enter the name(or part of the name) of the file to search : ";
        std::getline(std::cin, filename);
        auto results = search_files_by_name(directory, filename);
        std::cout << "Found files:\n";
        for (const auto& result : results) {
            std::cout << result << "\n";
        }
    }
    else if (choice == 2) {
        std::string search_term;
        std::cout << "Enter text to search the file contents: ";
        std::getline(std::cin, search_term);
        auto results = search_files_by_content(directory, search_term);
        std::cout << "Found files:\n";
        for (const auto& result : results) {
            std::cout << result << "\n";
        }
    }
    else {
        std::cout << "Wrong choice.\n";
    }

    return 0;
}