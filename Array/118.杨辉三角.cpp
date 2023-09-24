/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) return res;
        while (numRows--) {
            if (res.empty()) {
                res.push_back({1});
            }
            else {
                vector<int> temp;
                temp.push_back(1);
                for (int i = 1; i < res.back().size(); i++) {
                    temp.push_back(res.back()[i - 1] + res.back()[i]);
                }
                temp.push_back(1);
                res.push_back(temp);
            }
        }
        return res;
    }
};
// @lc code=end

