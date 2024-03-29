/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // n - k 最大表示第k个最小
        return quickselect(nums, 0, n - 1, n - k);
    }
    int quickselect(vector<int> &nums, int l, int r, int k) {
        if (l == r) return nums[k];
        // 随机选择
        int partition = nums[l];
        int i = l - 1, j = r + 1;
        while (i < j) {
            // 第一个不小于partition
            do i++; while(nums[i] < partition);
            // 第一个不大于partition
            do j--; while(nums[j] > partition);
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        if (k <= j) {
            return quickselect(nums, l, j, k);
        } else {
            return quickselect(nums, j + 1, r, k);
        }
    }
};
// @lc code=end

