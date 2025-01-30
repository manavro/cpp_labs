#include "Max_Profit.hpp"
#include <algorithm>

int maxProfit(const std::vector<int>& prices) {
    if (prices.empty()) return 0;

    int min_price = prices[0];
    int max_profit = 0;

    for (int price : prices) {
        min_price = std::min(min_price, price);
        int profit = price - min_price;
        max_profit = std::max(max_profit, profit);
    }

    return max_profit;
}