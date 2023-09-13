/*
 * @lc app=leetcode.cn id=2766 lang=cpp
 *
 * [2766] 重新放置石块
 */

// @lc code=start
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = 0; i < moveFrom.size(); i++) {
            s.erase(moveFrom[i]);
            s.insert(moveTo[i]);
        }
        vector<int> ans(s.begin(), s.end());
        sort(ans.begin(), ans.end());
        return ans;

    }
};
// @lc code=end

