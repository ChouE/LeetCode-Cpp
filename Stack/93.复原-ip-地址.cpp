/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
    static constexpr int SEG_COUNT = 4;
    vector<string> ans;
    vector<int> segments;
public:
    /**
     * @brief 
     * 
     * @param s: input string 
     * @param segId : segment id
     * @param segStart : start index of segment
     */
    void dfs(const string& s, int segId, int segStart) {
        // 到达末尾
        if (segId == SEG_COUNT) {
            if (segStart == s.size()) {
                // 还原ip地址
                string ipAddr;
                for (int i = 0; i < SEG_COUNT; ++i) {
                    ipAddr += to_string(segments[i]);
                    if (i != SEG_COUNT - 1) {
                        ipAddr += '.';
                    }
                }
                ans.push_back(std::move(ipAddr));
            }
            return;
        }
        // 段数不够的情况，到达末尾
        if (segStart == s.size()) {
            return;
        }
        // zero 
        if (s[segStart] == '0') {
            segments[segId] = 0;
            dfs(s, segId + 1, segStart + 1);
            return;
        }

        int addr = 0;
        for (int segEnd = segStart; segEnd < s.size(); ++segEnd) {
            addr = addr * 10 + (s[segEnd] - '0');
            if (addr > 0 && addr <= 0xFF) {
                segments[segId] = addr;
                dfs(s, segId + 1, segEnd + 1);
            } else {
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        segments.resize(SEG_COUNT);
        dfs(s, 0, 0);
        return ans;
    }
};
// @lc code=end

