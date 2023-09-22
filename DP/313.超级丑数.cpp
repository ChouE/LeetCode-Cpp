/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        // 小根堆, 解法超时。。。
        // 使用丑数性质，去掉哈希表
        priority_queue heap {greater<long>(), vector<long> {1L}};
        
        int ugly = 0;
        for (int i = 0; i < n; i++) {
            long curr = heap.top();
            heap.pop();
            ugly = static_cast<int>(curr);
            for (auto factor : primes) {
                long next = curr * factor;
                heap.push(next);
                if (curr % factor == 0) {
                    break;
                }
            }
        }
        return ugly;
    }
};
// @lc code=end

