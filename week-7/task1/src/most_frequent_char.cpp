#include "most_frequent_char.hpp"
#include <unordered_map>

std::pair<char, int> most_frequent_char(const std::string& s) {
    std::unordered_map<char, int> char_count;

    for (char c : s) {
        char_count[c]++;
    }

    char most_frequent = '\0';
    int max_count = 0;

    for (const auto& pair : char_count) {
        if (pair.second > max_count) {
            max_count = pair.second;
            most_frequent = pair.first;
        }
    }

    return { most_frequent, max_count };
}