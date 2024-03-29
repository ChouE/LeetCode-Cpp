/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
// 手撕排序算法
// 随机快速排序
#include <random>
class Solution {
    // 随机选择pivot，对数组进行划分
    int partition(std::vector<int>& arr, int low, int high, std::mt19937& gen) {
        std::uniform_int_distribution<> dis(low, high);
        // 随机选择，减少最坏时间复杂度
        int pivotIndex = dis(gen);
        int pivotValue = arr[pivotIndex];
        std::swap(arr[pivotIndex], arr[high]);
        // 表示小于pivotValue元素区域的右边界
        int storeIndex = low;

        for (int i = low; i < high; i++) {
            if (arr[i] < pivotValue) {
                // 将它与storeIndex处的值交换，扩大边界
                std::swap(arr[i], arr[storeIndex]);
                storeIndex++;
            }
        }
        // 放置基准值
        std::swap(arr[storeIndex], arr[high]);
        return storeIndex;
    }
    // 随机快速排序
    void quickSort(std::vector<int>& arr, int low, int high, std::mt19937& gen) {
        if (low < high) {
            int pivot = partition(arr, low, high, gen);
            quickSort(arr, low, pivot - 1, gen);
            quickSort(arr, pivot + 1, high, gen);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        std::random_device rd;
        std::mt19937 gen(rd());
        quickSort(nums, 0, nums.size() - 1, gen);
        return nums;
    }
};
// @lc code=end

