/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
    // 使用栈来存储数字
    // 遇到运算符就从栈中取出两个数字进行运算，然后将结果入栈
    // 最后栈中只剩下一个数字，就是结果
    bool isNumber(const string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        for ( int i = 0; i < n; i++) {
            string& token = tokens[i];
            if (isNumber(token)) {
                s.push(atoi(token.c_str()));
            } else {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                switch ( token[0] ) {
                    case '+': s.push(num1 + num2); break;
                    case '-': s.push(num1 - num2); break;
                    case '*': s.push(num1 * num2); break;
                    case '/': s.push(num1 / num2); break;
                }
            }
        }
        return s.top();
    }
};
// @lc code=end

