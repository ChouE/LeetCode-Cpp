/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto it1 = nums.begin(), it2 = nums.begin();
        while (it2 != nums.end()) {
            if (*it2 != 0) {
                std::swap(*it1, *it2);
                ++it1;
            }
            ++it2;
        }
        
    }
};
// @lc code=end

