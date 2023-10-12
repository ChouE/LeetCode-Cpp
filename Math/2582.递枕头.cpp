/*
 * @lc app=leetcode.cn id=2582 lang=cpp
 *
 * [2582] 递枕头
 */

// @lc code=start
class Solution {
public:
    int passThePillow(int n, int time) {
        // 2n - 2 个时间单位为一个循环
        // 前半部分是1 -> n - 1
        // 后半部分是n -> 2
        // time / ( n - 1 ) % 2 只有两个值， 0 或者 1
        // 0 代表前半部分， 1 代表后半部分
        // 前半部分 返回 time % (n - 1) + 1
        // 后半部分 返回 n - time % (n - 1)
        return time / (n - 1) % 2 ? n - time % (n - 1) : time % (n - 1) + 1;
    }
};
// @lc code=end

