/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        auto rob1 = [&](int start, int end) {
            int f0 = 0, f1 = 0;
            for (int i = start; i < end; i++) {
                int newf0 = max(f0 + nums[i], f1);
                f0 = f1;
                f1 = newf0;
            }
            return f1;
        };
        // 如果是长度为0的数组，直接返回0
        // 如果长度为1的数组，直接返回nums[0]
        // 如果长度为2的数组，直接返回max(nums[0], nums[1])，此处第一项和第二项分别就是nums[0]和nums[1]
    
        return max(nums[0] + rob1(2, n - 1), rob1(1, n));
    }
};
// @lc code=end

