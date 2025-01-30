#include <iostream>
#include "perms.hpp"

int main() {
    std::vector<int> numbers = { 1, 2, 3 };
    std::vector<std::vector<int>> permutations = perms(numbers);

    for (const auto& perm : permutations) {
        for (int num : perm) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}