#include "perms.hpp"
#include <algorithm>

void permute(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
    if (start >= nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        std::swap(nums[start], nums[i]);
        permute(nums, start + 1, result);
        std::swap(nums[start], nums[i]);
    }
}

std::vector<std::vector<int>> perms(const std::vector<int>& input) {
    std::vector<std::vector<int>> result;
    std::vector<int> nums = input;
    permute(nums, 0, result);
    return result;
}
