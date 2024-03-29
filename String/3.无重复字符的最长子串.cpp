/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        unordered_set<char> lookup;

        int ans = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            while (lookup.find(s[i]) != lookup.end()) {
                lookup.erase(s[left]);
                left++;
            }
            ans = max(ans, i - left + 1);
            lookup.insert(s[i]);
        }
        return ans;
    }
};
// @lc code=end

