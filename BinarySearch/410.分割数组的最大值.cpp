/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
#include <numeric>
class Solution {
    // 二分查找 + 贪心
public:
    int splitArray(vector<int>& nums, int k) {
        // 下界是0，非负整数数组
        // 上界可以是数组和，最大也不会超过这个值
        int l = 0, r = std::reduce(nums.begin(), nums.end());
        while (l < r) {
            int mid = l + (r - l) / 2;

            auto check = [&]() {
                int sum = 0, cnt = 0;
                for (auto x : nums) {
                    // 单个值大于mid，不能分
                    if (x > mid) return false;
                    // 当前的加和即将大于mid
                    if (sum + x > mid) {
                        cnt ++;
                        sum = x;
                    } else {
                        sum += x;
                    }
                }
                // 最后一段
                return ++cnt <= k;
            };

            if (check()) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};
// @lc code=end

