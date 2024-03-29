/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
    // 调整最大堆
    void heapify(std::vector<int>& arr, int n, int i) {
        int largest = i;
        int l = 2 * i + 1; //i的左孩子
        int r = 2 * i + 2; //i的右孩子
        // 如果左孩子大于根
        if (l < n && arr[l] > arr[largest]) {
            largest = l;
        }
        // 如果右骸子大于当前最大值
        if (r < n && arr[r] > arr[largest]) {
            largest = r;
        }
        // 如果最大值发生了变化
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            // 递归调整受到影响的子树
            heapify(arr, n, largest);
        }
    }
    void heapSort(std::vector<int>& arr) {
        int n = arr.size();
        // 建堆
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        // 从堆顶取出元素
        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};
// @lc code=end

