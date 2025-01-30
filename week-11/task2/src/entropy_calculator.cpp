#include "../include/entropy_calculator.h"
#include <iostream>
#include <fstream>
#include <cmath>

void calculateEntropy(const std::string& filePath) {
    std::unordered_map<char, int> frequencyMap;
    std::ifstream file(filePath);

    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    char ch;
    int totalChars = 0;

    while (file.get(ch)) {
        frequencyMap[ch]++;
        totalChars++;
    }
    file.close();

    double entropy = 0.0;

    for (const auto& pair : frequencyMap) {
        double p = static_cast<double>(pair.second) / totalChars;
        entropy -= p * log2(p);
    }

    std::cout << "Calculated entropy: " << entropy << std::endl;
}
