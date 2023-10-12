/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }
        sort(strNums.begin(), strNums.end(), [](string& s1, string& s2) {
            return s1 + s2 > s2 + s1;
        });
        string res = "";
        for (string& str : strNums) {
            res += str;
        }
        // "0" "0" -> "00" 特殊处理
        return res[0] == '0' ? "0" : res;
    }
};
// @lc code=end

