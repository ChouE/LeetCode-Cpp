/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        auto res {0};
        auto m {board.size()}, n {board[0].size()};
        for (int i {}; i < m; i++) {
            for (int j {}; j < n; j++) {
                if (i > 0 && board[i - 1][j] == 'X') continue;
                if (j > 0 && board[i][j - 1] == 'X') continue;
                if (board[i][j] == 'X') res++;
            }
        }
        return res;
    }
};
// @lc code=end

