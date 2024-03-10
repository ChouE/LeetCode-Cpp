/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnt;
        for (auto c : s) {
            cnt[c] ++;
        }
        int ans {};
        for (auto [a, k] : cnt) {
            ans += k / 2 * 2;
        }
        if (ans < s.size()) {
            ans ++;
        }
        return ans;
    }
};
// @lc code=end

