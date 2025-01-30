#include <iostream>
#include <string>
#include "most_frequent_char.hpp"

int main() {
    std::string input;
    std::cout << "Enter string: ";
    std::getline(std::cin, input);

    auto result = most_frequent_char(input);
    std::cout << "Result: ['" << result.first << "', " << result.second << "]" << std::endl;

    return 0;
}