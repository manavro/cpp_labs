#include <iostream>
#include <regex>

int main() {
    std::string email;
    std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    std::cout << "Enter an email address: ";
    std::getline(std::cin, email);

    if (std::regex_match(email, pattern)) {
        std::cout << "Valid email address" << std::endl;
    }
    else {
        std::cout << "Invalid email address" << std::endl;
    }

    return 0;
}
