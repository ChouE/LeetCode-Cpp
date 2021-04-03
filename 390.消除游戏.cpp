/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 */

// @lc code=start
class Solution {
public:
    int lastRemaining(int n) {
        //采用递归，而不是循环避免n值过大带来的内存问题
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n%2 != 0) return lastRemaining(n-1);
        else return 2*(1+n/2-lastRemaining(n/2));
        /*
        一行代码：
        return n == 1 ? 1 : 2*(1+n/2-lastRemaining(n/2));
        */
    }
};
// @lc code=end

