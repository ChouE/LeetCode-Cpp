#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <utility>

using namespace std;

pair<int,int> partition(vector<int>& arr, int left, int right) {
  int pivot = arr[right];
  int small = left - 1;
  int big = right;
  while (left < big) {
    if (arr[left] < pivot) {
        swap(arr[left++], arr[++small]);
    }
    else if (arr[left] > pivot) {
        swap(arr[left], arr[--big]);
    }else {
        left++;
    }
  }
  swap(arr[big], arr[right]);
  return {small + 1, big};
}

pair<int, int> randomPartition(vector<int>& arr, int left, int right) {
  // 随机数生成
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(left, right);
  int randomIndex = dis(gen);

  swap(arr[randomIndex], arr[right]);

  return partition(arr, left, right);
}

void ultimateQuickSort(vector<int>& arr, int left, int right) {
  if (left < right) {
    auto [p1, p2] = randomPartition(arr, left, right);
    ultimateQuickSort(arr, left, p1 - 1);
    ultimateQuickSort(arr, p2 + 1, right);
  }
}

int main() {
  vector<int> arr = {5, 2, 8, 1, 9, 3, 7, 6, 4, 3, 3, 3};
  cout << "Original array: ";
  for (int num : arr) cout << num << " ";
  cout << endl;

  ultimateQuickSort(arr, 0, arr.size() - 1);

  cout << "Sorted array: ";
  for (int num : arr) cout << num << " ";
  cout << endl;
  return 0;
}