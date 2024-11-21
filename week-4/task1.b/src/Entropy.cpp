#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include "Entropy.hpp"

double calculateShannonEntropy(const std::string& input) {
    if (input.empty()) {
        
    }

    std::unordered_map<char, int> frequency;
    int length = input.size();

 
    for (char c : input) {
        frequency[c]++;
    }

    double entropy = 0.0;

    
    for (const auto& pair : frequency) {
        double probability = static_cast<double>(pair.second) / length;
        entropy -= probability * std::log2(probability);
    }

    return entropy;
}
