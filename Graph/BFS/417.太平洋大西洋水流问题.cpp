/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
    vector<vector<int>> heights;

    void bfs(int row, int col, vector<vector<int>> &ocean) {
        // 已经访问过
        if (ocean[row][col]) return;
        ocean[row][col] = 1;
        int m = heights.size(), n = heights[0].size();
        // 上下左右
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : dirs) {
            int newRow = row + dir[0], newCol = col + dir[1];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col]) {
                bfs(newRow, newCol, ocean);
            }
        }
        
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        if(heights.empty() || heights[0].empty()) return {};
        int m = heights.size(), n = heights[0].size();
        // 太平洋
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        // 大西洋
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        // 从四周开始搜索
        for (int i {}; i < m; i++) {
            bfs(i, 0, pacific);
        }
        for (int i {}; i < n; i++) {
            bfs(0, i, pacific);
        }
        for (int i {}; i < m; i++) {
            bfs(i, n - 1, atlantic);
        }
        
        for (int i {}; i < n - 1; i++) {
            bfs(m - 1, i, atlantic);
        }
        vector<vector<int>> res;
        for (int i {}; i < m; i++) {
            for (int j {}; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
// @lc code=end

