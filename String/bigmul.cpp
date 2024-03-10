#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

using dur_t = std::chrono::duration<double>;
class Timer {
private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start;
  std::chrono::time_point<std::chrono::high_resolution_clock> end;
  dur_t duration;

public:
  Timer() : start(std::chrono::high_resolution_clock::now()) {}
  ~Timer() {
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Time: " << duration.count() << " seconds\n";
  }
};

std::string multiplyLargeNumbers(std::string num1, std::string num2) {
  if (num1 == "0" || num2 == "0") {
    return "0";
  }
  std::vector<int> result(num1.size() + num2.size(), 0);
  std::reverse(num1.begin(), num1.end());
  std::reverse(num2.begin(), num2.end());
  for (size_t i = 0; i < num1.size(); ++i) {
    for (size_t j = 0; j < num2.size(); ++j) {
      result[i + j] += (num1[i] - '0') * (num2[j] - '0');
      result[i + j + 1] += result[i + j] / 10;
      result[i + j] %= 10;
    }
  }
  // remove leading zeros
  while (result.size() > 1 && result.back() == 0) {
    result.pop_back();
  }

  std::string res;
  for (auto it = result.rbegin(); it != result.rend(); ++it) {
    res += std::to_string(*it);
  }
  return res;
}
int main() {
  std::string num1 = "2";
  std::string res = "1";
  {
    Timer t;
    for (int i = 0; i < 1000; ++i) {
      res = multiplyLargeNumbers(res, num1);
    }
  }

  std::cout << "2 to the power of 1000 is:" << res << '\n';
  return 0;
}