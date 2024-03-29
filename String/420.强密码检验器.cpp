/*
 * @lc app=leetcode.cn id=420 lang=cpp
 *
 * [420] 强密码检验器
 */

// @lc code=start
class Solution {
public:
  int strongPasswordChecker(string password) {
    /**
     * @par n = password.size()
     * @par k = types of password, at least 3
     * n < 6: max{6 - n, 3 - k}
     * n >= 6 && n <= 20: successively 3 times, modify is the best choice
     * max {3- k,modify times}, modify times = sum(ss / 3), ss is size of
     * successive same char n > 20: delete times = n - 20, modify times = sum(ss
     * / 3), insert times = max{delete times, 3 - k} greedy: delete
     */
    int a{}, b{}, c{}, n = password.size(), k{};
    for (auto ch : password) {
      // a: number, b: lower, c: upper
      if (ch >= '0' && ch <= '9') {
        a = 1;
      } else if (ch >= 'a' && ch <= 'z') {
        b = 1;
      } else if (ch >= 'A' && ch <= 'Z') {
        c = 1;
      }
    }
    // k: types of password
    k = a + b + c;
    if (n < 6) {
      return max(6 - n, 3 - k);
    } else {
      // p is modify times, sum(ss / 3)
      int p{0}, del{n - 20}, res{del};
      // d[0] : aaa, d[1]: aaaa, d[2]: aaaaa , like
      int d[3] = {0};
      for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && password[j] == password[i]) {
          j++;
        }
        int len = j - i;
        i = j - 1;
        // sum(ss / 3)
        p += len / 3;
        if (len >= 3)
          d[len % 3]++;
      }
      if (n <= 20) {
        return max(p, 3 - k);
      }
      // n > 20, del > 0
      if (d[0] && del > 0) {
        int t = min(del, d[0]);
        del -= t;
        p -= t;
      }
      if (d[1] && del > 0) {
        // d[1] * 2: aaaa -> aa
        int t = min(del, d[1] * 2);
        del -= t;
        p -= t / 2;
      }
      if (p && del > 0) {
        // d[2] * 3: aaaaa -> aa
        int t = min(p * 3, del);
        p -= t / 3;
      }
      return res + max(p, 3 - k);
    }
    return 0;
  }
};
// @lc code=end
