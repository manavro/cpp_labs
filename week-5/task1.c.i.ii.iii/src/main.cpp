#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cmath>
#include <string>
#include <vector>

double calculateShannonEntropy(std::ifstream& file) {
    std::unordered_map<char, int> frequencyMap;
    char c;
    int totalCharacters = 0;

    while (file.get(c)) {
        frequencyMap[c]++;
        totalCharacters++;
    }

    if (totalCharacters == 0) {
        throw std::runtime_error("Error: File is empty.");
    }

    double entropy = 0.0;

    for (const auto& pair : frequencyMap) {
        double probability = static_cast<double>(pair.second) / totalCharacters;
        entropy -= probability * log2(probability);
    }

    return entropy;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Error: Invalid number of arguments.Use : "
            << argv[0] << " <input_file_name> <output_file_name>" << std::endl;
        return 1;
    }

    const std::string inputFilename = argv[1];
    const std::string outputFilename = argv[2];

    std::ifstream inputFile(inputFilename, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Failed to open file '" << inputFilename << "'." << std::endl;
        return 1;
    }

    double entropy;
    try {
        entropy = calculateShannonEntropy(inputFile);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    inputFile.close();

    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Failed to open file '" << outputFilename << "' for recording." << std::endl;
        return 1;
    }

    outputFile << "Shannon entropy: " << entropy << std::endl;
    outputFile.close();

    std::cout << "Shannon entropy: " << entropy << std::endl;
    std::cout << "The result is written to a file. '" << outputFilename << "'." << std::endl;

    return 0;
}