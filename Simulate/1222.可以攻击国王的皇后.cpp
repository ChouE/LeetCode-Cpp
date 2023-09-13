/*
 * @lc app=leetcode.cn id=1222 lang=cpp
 *
 * [1222] 可以攻击国王的皇后
 */

// @lc code=start
class Solution {
public:
    // 以皇后为中心寻找国王的方法
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        // 符号函数
        auto sgn = [](int x) -> int {
            return x > 0 ? 1 : (x == 0 ? 0 : -1);
        };
        using pvii = pair<vector<int>, int>;
        // mp的key是方向，value是皇后位置和距离
        unordered_map<int, pvii> mp;
        // 国王位置
        int kx = king[0], ky = king[1];
        for (const auto& queen : queens) {
            // 皇后位置
            int qx = queen[0], qy = queen[1];
            // 位置差值
            int x = qx - kx, y = qy - ky;
            // 处于能够攻击的状态的条件
            if (x == 0 || y == 0 || abs(x) == abs(y)) {
                // dx和dy代表了方向
                int dx = sgn(x), dy = sgn(y);
                int key = dx * 10 + dy;
                // 第一个条件是没有皇后，第二个条件是有皇后但是距离更近
                if (mp.find(key) == mp.end() || abs(x) + abs(y) < mp[key].second) {
                    // 更新皇后位置和距离
                    mp[key] = make_pair(queen, abs(x) + abs(y));
                }
            }
        }
        vector<vector<int>> ans;
        for (const auto& [_, p] : mp) {
            // 只需要皇后位置
            ans.push_back(p.first);
        }
        return ans;
    }
};
// @lc code=end

