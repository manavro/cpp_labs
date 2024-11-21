#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include "Entropy.hpp"


int main() {
    std::string input;

    std::cout << "Enter line to calculate entropy: ";
    std::getline(std::cin, input);

    double entropy = calculateShannonEntropy(input);

    std::cout << "Shannon entropy: " << std::fixed << std::setprecision(2) << entropy << std::endl;

    return 0;
}
