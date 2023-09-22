/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        array factors {2, 3, 5};
        unordered_set<long> seen;
        // 小根堆
        priority_queue heap {greater<long>(), vector<long> {1L}};
        seen.insert(1);
        int ugly = 0;
        for (int i = 0; i < n; i++) {
            long curr = heap.top();
            heap.pop();
            ugly = static_cast<int>(curr);
            for (auto factor : factors) {
                long next = curr * factor;
                if (!seen.count(next)) {
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }
        return ugly;
    }
};
// @lc code=end

