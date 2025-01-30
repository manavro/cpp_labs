#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter string: ";
    std::getline(std::cin, input);

    std::regex pattern("(.)\\1{2,}");

    std::string result = std::regex_replace(input, pattern, "\$1");

    std::cout << "Result: " << result << std::endl;

    return 0;
}
