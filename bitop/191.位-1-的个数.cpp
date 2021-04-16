/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 * 题目最直观的思路即进行一次遍历，统计1出现的次数，这样的算法复杂度为O(32)
 * 使用位运算进行优化，n&n-1的运算结果为将n的最低的1变为0，不断进行这样的运算，直到n为0即可计算出1的个数
 * 这样得到的算法的最坏复杂度为O(logn),即全为1的时候需要进行logn次循环，而logn一定不超过32
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int r = 0;
        while(n){
            n &= n-1;
            r++;
        }
        return r;
    }
};
// @lc code=end

