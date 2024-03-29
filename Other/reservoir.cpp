#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

/**
 * @brief
 *
 * @param data 数据流
 * @param k 池子大小
 * @return std::vector<int> 抽样
 */
std::vector<int> reservoirSample(std::vector<int>& data, int k) {
  std::vector<int> reservoir(k);
  int i;
  if (k >= data.size()) {
    return data;
  }
  for (i = 0; i < k; ++i) {
    reservoir[i] = data[i];
  }
  // random gen
  std::random_device rd;
  std::mt19937 gen(rd());

  while (i < data.size()) {
    std::uniform_int_distribution<> dis(0, i);
    int j = dis(gen);
    if (j < k) {
      reservoir[j] = data[i];
    }
    ++i;
  }
  return reservoir;
}
int main() {
  std::vector<int> v(10);
  std::iota(v.begin(), v.end(), 1);
  int repeat = 10000;
  std::vector<int> t(10);
  for (int i = 0; i < repeat; i++) {
    auto res = reservoirSample(v, 4);
    for (int num : res) {
      t[num - 1]++;
    }
  }
  for (int time : t) {
    std::cout << static_cast<double>(time) / repeat << " ";
  }
  return 0;
}