/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        size_t len = s.length();
        // 去除前导空格
        int index = 0;
        while (index < len && s[index] == ' ') {
            index++;
        }
        if (index == len) {
            return 0;
        }
        // 判断符号位
        int sign = 1;
        if (s[index] == '+') {
            index ++;
        } else if(s[index] == '-') {
            sign = -1;
            index ++;
        }
        int res = 0;
        while (index < len) {
            char curChar = s[index];
            if (curChar > '9' || curChar < '0') {
                break;
            }
            int term = curChar - '0';
            //res = res * 10 + term;
            // 提前判断是否溢出
            if (res > (INT_MAX - term) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + term; 
            index++;
            
        }
        return sign * res;
    }
};
// @lc code=end

