#include <algorithm>
#include <iostream>
#include <vector>

// 假设排序的都是非负整数
void countSort(std::vector<int> &arr) {
  int maxElement = *std::ranges::max_element(arr);
  std::vector<int> count(maxElement + 1, 0);
  std::vector<int> output(arr.size());
  // 统计num的出现次数
  for (int num : arr) {
    count[num]++;
  }
  // 累加数组
  for (size_t i = 1; i < count.size(); ++i) {
    count[i] += count[i - 1];
  }
  // 反向填充数组
  for (int i = arr.size() - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }
  for (size_t i = 0; i < arr.size(); i++) {
    arr[i] = output[i];
  }
}

int main() {
  std::vector<int> data{4, 2, 2, 6, 3, 3, 1};
  countSort(data);
  for (int num : data) {
    std::cout << num << ' ';
  }
}