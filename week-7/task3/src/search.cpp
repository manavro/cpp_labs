#include "search.hpp"
#include <fstream>
#include <iostream>
#include <vector>


std::vector<fs::path> search_files_by_name(const fs::path& directory, const std::string& filename) {
    std::vector<fs::path> results;
    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().filename().string().find(filename) != std::string::npos) {
            results.push_back(entry.path());
        }
    }
    return results;
}

std::vector<fs::path> search_files_by_content(const fs::path& directory, const std::string& search_term) {
    std::vector<fs::path> results;
    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            std::ifstream file(entry.path());
            std::string line;
            while (std::getline(file, line)) {
                if (line.find(search_term) != std::string::npos) {
                    results.push_back(entry.path());
                    break;
                }
            }
        }
    }
    return results;
}