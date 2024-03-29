/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if ( n < 3 ) return 0;
        vector<int> adj(n);
        adjacent_difference(nums.begin(), nums.end(), adj.begin());
        int res = 0;
        for (int i = 1; i < n; ) {
            int j  = i;
            while (j < n && adj[j] == adj[i]) {
                ++j;
            }
            int k = j - i;
            res += k * (k - 1) / 2;
            i = j;
        }
        return res;
    }
};
// @lc code=end

