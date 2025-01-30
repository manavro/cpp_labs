#include <iostream>
#include <vector>
#include <sstream>
#include "max_water_container.hpp"

int main() {
    std::string input;
    std::cout << "Enter numbers separated by commas: ";
    std::getline(std::cin, input);

   
    std::vector<int> heights;
    std::stringstream ss(input);
    std::string item;

    while (std::getline(ss, item, ',')) {
        heights.push_back(std::stoi(item));
    }

    
    int result = maxArea(heights);
    std::cout << "Maximum water volume: " << result << std::endl;

    return 0;
}