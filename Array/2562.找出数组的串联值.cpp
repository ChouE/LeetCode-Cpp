/*
 * @lc app=leetcode.cn id=2562 lang=cpp
 *
 * [2562] 找出数组的串联值
 */

// @lc code=start
#include <string>
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res {};
        for (int left = 0, right = nums.size() - 1; left <= right; ++left, --right) {
            if ( left != right) {
                res += std::stoi(std::to_string(nums[left]) + std::to_string(nums[right]));
            } else {
                res += nums[left];
            }
        }
        return res;
    }
};
// @lc code=end

