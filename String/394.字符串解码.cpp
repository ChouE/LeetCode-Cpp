/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string getDigits(string &s, size_t &ptr) {
        // number use string
        string res = "";
        while(isdigit(s[ptr])) {
            res.push_back(s[ptr++]);
        }
        return res;
    }
    string getString(vector<string>& v) {
        string res;
        for (const auto &s : v) {
            res += s;
        }
        return res;
    }
    string decodeString(string s) {
        vector<string> stk;
        size_t pos = 0;
        while (pos < s.size()) {
            char cur = s[pos];
            if (isdigit(cur)) {
                string digits = getDigits(s, pos);
                // number at the top of stk
                stk.push_back(digits);
            } else if (isalpha(cur) || cur == '[') {
                stk.push_back(string(1,s[pos++]));
            } else {
                // cur == ']'
                ++pos;
                vector<string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                // "[" at the top of stk
                stk.pop_back();
                // number at the top of stk
                int repeat = stoi(stk.back());
                stk.pop_back();
                string t, o = getString(sub);
                while (repeat--) {
                    t += o;
                }
                stk.push_back(t);

            }
        }
        return getString(stk);
    }
};
// @lc code=end

