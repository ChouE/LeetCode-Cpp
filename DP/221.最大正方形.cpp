/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /**
         * 解法: 动态规划
         * 状态定义：dp[i][j] 表示以 (i, j) 为右下角，且只包含 1 的正方形的边长最大值
         * 该位置为0，则dp[i][j] = 0
         * 该位置为1，则dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
         * base case: dp[0][j] = matrix[0][j]，dp[i][0] = matrix[i][0]
         */
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        // 最大边长
        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns,0));
        for (int i = 0; i < rows; i++) {
            dp[i][0] = matrix[i][0] - '0';
            // 更新最大边长, 处理只有一行的情况
            maxSide = max(maxSide, dp[i][0]);
        }
        for (int j = 0; j < columns; j++) {
            dp[0][j] = matrix[0][j] - '0';
            maxSide = max(maxSide, dp[0][j]);
        }
        
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                } else {
                    dp[i][j] = 0;
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
        // 返回面积
        return maxSide * maxSide;
    }
};
// @lc code=end

