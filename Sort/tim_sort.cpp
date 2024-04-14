#include <iostream>
#include <random>
#include <vector>

const int RUN = 32;

void insertSort(std::vector<int>& arr, int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int temp = arr[i];
    int j = i - 1;
    while (j >= left && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

void merge(std::vector<int>& arr, int l, int m, int r) {
  int len1 = m - l + 1;
  int len2 = r - m;
  std::vector<int> left(len1), right(len2);
  for (int i = 0; i < len1; i++) {
    left[i] = arr[l + i];
  }
  for (int i = 0; i < len2; i++) {
    right[i] = arr[m + 1 + i];
  }

  int i = 0;
  int j = 0;
  int k = l;
  while (i < len1 && j < len2) {
    if (left[i] <= right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
  }
  while (i < len1) {
    arr[k++] = left[i++];
  }
  while (j < len2) {
    arr[k++] = right[j++];
  }
}

void timSort(std::vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n; i += RUN) {
    insertSort(arr, i, std::min((i + RUN - 1), (n - 1)));
  }
  for (int size = RUN; size < n; size = 2 * size) {
    for (int left = 0; left < n; left += 2 * size) {
      int mid = left + size - 1;
      // 最后一段可能是不足的
      int right = std::min((left + 2 * size - 1), (n - 1));
      if (mid < right) {
        merge(arr, left, mid, right);
      }
    }
  }
}
std::vector<int> generate_arr(int n) {
  std::mt19937 gen{std::random_device{}()};
  std::vector<int> ret(n);
  std::uniform_int_distribution<> dis(0, 1000);
  for (int i = 0; i < n; i++) {
    ret[i] = dis(gen);
  }
  return ret;
}

int main() {
  std::vector<int> arr = generate_arr(500);
  for (int a : arr) {
    std::cout << a << ' ';
  }
  std::cout << '\n';
  timSort(arr);
  for (int a : arr) {
    std::cout << a << ' ';
  }
  std::cout << '\n';
  return 0;
}