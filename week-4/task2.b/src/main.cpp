#include <iostream>
#include <regex>

int main() {
    setlocale(LC_ALL, "RU");
    std::string ipv6;
    std::regex pattern("^(?:[0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$");

    std::cout << "Enter the IPv6 address in full form: ";
    std::getline(std::cin, ipv6);

    if (std::regex_match(ipv6, pattern)) {
        std::cout << "Correct IPv6 address" << std::endl;
    }
    else {
        std::cout << "Incorrect IPv6 address" << std::endl;
    }

    return 0;
}
