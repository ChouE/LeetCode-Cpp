#include <algorithm>
#include <iostream>
#include <vector>

// 三傻排序
// 冒泡排序
// 最好时间复杂度：有序，O(N)
// 平均和最坏：O(N^2)
// 稳定排序，比较时只有大于才进行，相等则不会改变相对位置
void bubbleSort(std::vector<int>& nums) {
  int n = nums.size();
  bool swapped;
  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        std::swap(nums[j], nums[j + 1]);
        swapped = true;
      }
    }
    // 如果没有发生交换，已经有序，可以提前退出
    if (!swapped) {
      break;
    }
  }
}

// 插入排序
// 最好时间复杂度：O(N)
// 平均和最坏复杂度：O(N^2)
// 稳定排序
void insertionSort(std::vector<int>& nums) {
  // 将第一个元素视为有序
  // 从第二个开始，每个元素找到属于它的位置
  int n = nums.size();
  for (int i = 1; i < n; i++) {
    int key = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] > key) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = key;
  }
}

// 选择排序
// 复杂度O(N ^ 2)
// 不稳定排序
void selectionSort(std::vector<int>& nums) {
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    int min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (nums[j] < nums[min_index]) {
        min_index = j;
      }
    }
    if (min_index != i) {
      std::swap(nums[i], nums[min_index]);
    }
  }
}

int main() {
  std::vector<int> nums{8, 3, 5, 2, 4, 1, 6, 8, 9};
  // bubbleSort(nums);
  insertionSort(nums);
  // selectionSort(nums);
  std::for_each(nums.begin(), nums.end(), [](int n) { std::cout << n << " "; });
  return 0;
}