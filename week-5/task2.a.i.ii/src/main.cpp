#include <iostream>
#include <string>
#include "Converter.h"

int main() {
    std::cout << "Enter message to convert:\n";
    std::string user_input;
    std::getline(std::cin, user_input);

    std::cout << "Select type to convert:\n";
    std::cout << "1. Integer (int)\n";
    std::cout << "2. Floating point number (float)\n";
    std::cout << "3. String (str)\n";

    std::cout << "Your choice (1/2/3): ";
    int choice;
    std::cin >> choice;

    try {
        if (choice == 1) {
            int result = convert_to_int(user_input);
            std::cout << "Result: " << result << " (type: int)\n";
        }
        else if (choice == 2) {
            double result = convert_to_float(user_input);
            std::cout << "Result: " << result << " (type: float)\n";
        }
        else if (choice == 3) {
            std::string result = convert_to_str(user_input);
            std::cout << "Result: " << result << " (type: str)\n";
        }
        else {
            std::cout << "Error: Wrong choice. Please select 1, 2 or 3.\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
