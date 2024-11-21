#include <iostream>
#include <string>
#include <vector>
#include "Count.hpp"

int main() {
    std::string target;
    int N;

    std::cout << "Enter a search string: ";
    std::getline(std::cin, target);

    std::cout << "Enter the number of lines to check: ";
    std::cin >> N;
    std::cin.ignore();

    std::vector<std::string> strings(N);

    for (int i = 0; i < N; ++i) {
        std::cout << "Enter string " << i + 1 << ": ";
        std::getline(std::cin, strings[i]);
    }

    for (int i = 0; i < N; ++i) {
        int occurrences = countOccurrences(strings[i], target);
        std::cout << "In line " << i + 1 << " find " << occurrences << " occurrences of the string \"" << target << "\"." << std::endl;
    }

    return 0;
}
