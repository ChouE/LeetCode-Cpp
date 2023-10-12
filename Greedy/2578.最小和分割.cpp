/*
 * @lc app=leetcode.cn id=2578 lang=cpp
 *
 * [2578] 最小和分割
 */

// @lc code=start
#include <string>
class Solution {
public:
    int splitNum(int num) {
        std::string s = std::to_string(num);
        std::sort(s.begin(), s.end());
        std::array<int, 2> res {};
        for (int i = 0; i < s.size(); ++i) {
            res[i % 2] = res[i % 2] * 10 + s[i] - '0';
        }
        return res[0] + res[1];
    }
};
// @lc code=end

