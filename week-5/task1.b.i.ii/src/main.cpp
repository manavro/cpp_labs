#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cmath>
#include <string>


double calculateShannonEntropy(const std::string& data) {
    std::unordered_map<char, int> frequencyMap;
    for (char c : data) {
        frequencyMap[c]++;
    }

    double entropy = 0.0;
    int totalCharacters = data.size();

    for (const auto& pair : frequencyMap) {
        double probability = static_cast<double>(pair.second) / totalCharacters;
        entropy -= probability * log2(probability);
    }

    return entropy;
}

int main(int argc, char* argv[]) {

    if (argc != 2) { 
        std::cerr << "Error: Invalid number of arguments. Use: " << argv[0] << "<file_name>" << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "'." << std::endl;
        return 1;
    }

    std::string data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    if (data.empty()) {
        std::cerr << "Error: File is empty." << std::endl;
        return 1;
    }

    double entropy = calculateShannonEntropy(data);
    std::cout << "Shannon entropy: " << entropy << std::endl;

    return 0;
}
