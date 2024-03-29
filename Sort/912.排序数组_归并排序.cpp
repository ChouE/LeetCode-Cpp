/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start

// 归并排序
// 需要额外空间，但是是稳定排序

class Solution {
  void merge(std::vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
      L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
      R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
      // 保证稳定
      if (L[i] <= R[j]) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = R[j];
        j++;
      }
      k++;
    }
    // 拷贝剩余的元素
    while (i < n1) {
      arr[k++] = L[i++];
    }
    while (j < n2) {
      arr[k++] = R[j++];
    }
  }
  void mergeSort(std::vector<int> &arr, int left, int right) {
    if (left < right) {
      int mid = left + (right - left) / 2;
      mergeSort(arr, left, mid);
      mergeSort(arr, mid + 1, right);
      merge(arr, left, mid, right);
    }
  }

public:
  vector<int> sortArray(vector<int> &nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }
};
// @lc code=end
