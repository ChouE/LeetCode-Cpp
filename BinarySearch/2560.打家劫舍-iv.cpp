/*
 * @lc app=leetcode.cn id=2560 lang=cpp
 *
 * [2560] 打家劫舍 IV
 */

// @lc code=start
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // 最小最大值问题
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        while (left <= right) {
            // 二分查找
            int mid = (left + right) >> 1;
            int count = 0;
            bool visited = false;
            for (int x : nums) {
                // 从左到右遍历，如果当前值小于等于mid，且上一个值大于mid，则count++
                if (x <= mid && !visited) {
                    ++count;
                    visited = true;
                } else {
                    visited = false;
                }
            }
            // 遍历完之后进行检查
            // 如果小于mid的数量大于等于k，则说明mid太大了，需要缩小范围
            if (count >= k) {
                right = mid - 1;
            } else {
                // 反之，说明mid太小了，需要扩大范围
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

