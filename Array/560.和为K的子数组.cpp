#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int subarraySum(std::vector<int>& nums, int k) {
    // key： 前缀和， value：出现次数
  std::unordered_map<int, int> mp;
  mp[0] = 1;
  int count{}, pre{};
  for (auto num : nums) {
    // 前缀和 
    pre += num;
    if (mp.find(pre - k) != mp.end()) {
      count += mp[pre - k];
    }
    mp[pre]++;
  }
  return count;
}

int main() {
    std::vector t1 {1, 2, 3, 4, 3};
    std::cout << subarraySum(t1, 3);
    return 0;
}