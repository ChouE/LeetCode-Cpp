#include <iostream>

using namespace std;
// TODO: 去除重复的字符串
int main() {
    int n;
    cin >> n;
    long long ans {1};
    if (n % 2) {
        // n为奇数，n-1长度的回文串，n-1为偶数 + n个位置的26个字母的随机选择
        int times = (n - 1) / 2;
        for (int i = 0; i < times; i++) {
            ans = (ans * 26) % 998244353;
        }
        ans = (ans * n * 26) % 998244353;
    } else {
        // n为偶数，n-1为奇数
        int times = (n - 2) / 2 + 1;
        for (int i = 0; i < times; i++) {
            ans = (ans * 26) % 998244353;
        }
        ans = (ans * n * 26) % 998244353;
    }
    cout << ans;
}