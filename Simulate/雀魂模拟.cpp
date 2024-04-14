bool check(array<int, 10>& times) {
  array<int, 10> tmp{0};
  // 将i作为雀头
  for (int i = 1; i < 10; i++) {
    if (times[i] < 2) {
      continue;
    }
    bool ok{true};
    tmp = times;
    tmp[i] -= 2;
    for (int j = 1; j < 10 && ok; j++) {
      // 作为刻子
      if (tmp[j] >= 3) {
        tmp[j] -= 3;
      }
      while (tmp[j] && ok) {
        if (j + 2 > 9) {
          ok = false;
          break;
        }
        if (tmp[j + 1] && tmp[j + 2]) {
          tmp[j]--;
          tmp[j + 1]--;
          tmp[j + 2]--;
        } else {
          ok = false;
        }
      }
    }
    if (ok) return true;
  }
  return false;
}
vector<int> getTheNumber(vector<int>& cards) {
  sort(cards.begin(), cards.end());
  array<int, 10> times{0};
  vector<int> ans;
  for (int i = 0; i < 13; i++) {
    times[cards[i]]++;
  }
  for (int i = 1; i < 10; i++) {
    if (times[i] < 4) {
      // 尝试加一个，检查能否和牌
      times[i]++;
      if (check(times)) {
        ans.push_back(i);
      }
      times[i]--;
    }
  }
  if (ans.empty()) {
    ans.push_back(0);
  }
  return ans;
}