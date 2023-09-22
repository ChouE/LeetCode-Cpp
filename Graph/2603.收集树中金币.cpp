/*
 * @lc app=leetcode.cn id=2603 lang=cpp
 *
 * [2603] 收集树中金币
 */

// @lc code=start
class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        // 记录图
        vector<vector<int>> g(n);
        // 记录节点度数
        vector<int> deg(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
            deg[x]++, deg[y]++;
        }
        int left_edgs = n - 1;
        // 拓扑排序，去掉度数为1且无金币的节点
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1 && coins[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            left_edgs--;
            int x = q.front();
            q.pop();
            for (auto &y : g[x]) {
                // 如果去掉之后成为了新的满足条件的节点，加入队列
                if (--deg[y] == 1 && coins[y] == 0) {
                    q.push(y);
                }
            }
        }
        
        
        for (int i = 0; i < n; i++) {
            // 有金币的节点度数为1，需要去掉
            if (deg[i] == 1 && coins[i] != 0) {
                cout << i << " ";
                q.push(i);
            }
        }
        
        left_edgs -= q.size();
        // for (int x = q.front(); !q.empty(); q.pop(), x = q.front()) {
        //     //cout << x << " ";
        //     for (int y : g[x]) {
        //         if (--deg[y] == 1) {
        //             left_edgs--;
        //             // cout << left_edgs << " ";
        //         }
        //     }
        // }
        while (!q.empty()) {
            int x = q.front();
            for (int y : g[x]) {
                if (--deg[y] == 1) left_edgs--;
            }
            q.pop();
        }
        
        // 剩余的边数*2即为答案
        return max(left_edgs * 2, 0);
    }
};
// @lc code=end

