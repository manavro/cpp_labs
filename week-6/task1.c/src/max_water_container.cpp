#include "max_water_container.hpp"
#include <algorithm>

int maxArea(const std::vector<int>& heights) {
    int left = 0, right = heights.size() - 1;
    int max_volume = 0;

    while (left < right) {
        int width = right - left;
        int height = std::min(heights[left], heights[right]);
        max_volume = std::max(max_volume, width * height);
        if (heights[left] < heights[right]) {
            ++left;
        }
        else {
            --right;
        }
    }

    return max_volume;
}