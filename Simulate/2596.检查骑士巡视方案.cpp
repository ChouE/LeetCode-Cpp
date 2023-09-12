/*
 * @lc app=leetcode.cn id=2596 lang=cpp
 *
 * [2596] 检查骑士巡视方案
 */

// @lc code=start
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        // 检查左上角
        if (grid[0][0] != 0) return false;
        // 建立映射关系
        int n = grid.size();
        vector<array<int, 2>> indices(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                indices[grid[i][j]] = {i, j};
            }
        }
        for (int i = 1; i < indices.size(); i++) {
            int dx = abs(indices[i][0] - indices[i - 1][0]);
            int dy = abs(indices[i][1] - indices[i - 1][1]);
            if (dx * dy != 2) return false;
        }
    return true;
    }
};
// @lc code=end

