#include <iostream>
#include <vector>
#include "Max_Profit.hpp"

int main() {
    int y;
    std::vector<int> prices;
    std::cout << "Enter the elements of the vector (enter any non-numeric character to complete): ";

    while (std::cin >> y) {
        prices.push_back(y);
    }
    std::cout << "Max Profit: " << maxProfit(prices) << std::endl;
    return 0;
}