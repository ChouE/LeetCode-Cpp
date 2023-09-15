/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // nums 只包含正整数且非空
        // 问题可以转化为 0-1 背包问题
        // 选定一些数字，使得这些数字的和等于整个数组元素和的一半
        int n = nums.size();
        if (n < 2) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // 奇数不可能分成两个和相等的子集
        if (sum & 1) return false;
        int target = sum / 2;
        // 最大值大于 target 也不可能分成两个和相等的子集
        if (*max_element(nums.begin(), nums.end()) > target) return false;
        // dp[i][j] 表示从数组的 [0,i] 下标范围内选取若干个正整数（可以是 0 个），
        // 是否存在一种选取方案使得被选取的正整数的和等于 j
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // base case
        // dp[..][0] = true，因为不选取任何正整数就可以凑出和为 0 的方案
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        // dp[0][..] = false，因为没有任何正整数可选取,这种情况已经初始化为 false 了
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                } else { 
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};
// @lc code=end

