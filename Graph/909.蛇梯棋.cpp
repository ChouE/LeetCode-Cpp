/*
 * @lc app=leetcode.cn id=909 lang=cpp
 *
 * [909] 蛇梯棋
 */

// @lc code=start
class Solution {
private:
    // 将编号为 id 的格子转换为行列编号
    pair<int, int> id2rc(int id, int n) {
        int r = (id - 1) / n, c = (id - 1) % n;
        // 奇数行，从右到左编号
        if (r % 2 == 1) {
            c = n - 1 - c;
        }
        // 从下到上的行编号
        return {n - 1 - r, c};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> vis(n * n + 1);
        // q里面放的pair<int, int>，第一个int是格子编号，第二个int是走到这个格子的步数
        queue<pair<int, int>> q;
        // 将起点加入队列
        q.emplace(1, 0);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 1; i <= 6; ++i) {
                int ne = p.first + i; // 掷骰子的结果
                if (ne > n * n) { // 超出边界
                    break;
                }   
                auto rc = id2rc(ne, n); // 得到对应的行列
                if (board[rc.first][rc.second] > 0) { // 存在蛇或梯子
                    ne = board[rc.first][rc.second];
                }
                if (ne == n * n) { // 到达终点
                    return p.second + 1;
                }
                if (!vis[ne]) {
                    vis[ne] = true;
                    q.emplace(ne, p.second + 1); // 扩展新状态
                }
            }
        }
        return -1;
    }
};
// @lc code=end

