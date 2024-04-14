#include <iostream>
#include <vector>
#include <queue>
#include <print>
#include <format>
#include <ranges>
using namespace std;

vector<int> findtopk(vector<vector<int>> &nums, int k) {
    // nums 中每个都是降序的
    priority_queue<pair<int, int>> pq;
    int n = nums.size();
    vector<int> ans(k);
    vector<int> index(n);
    for (int i = 0; i < n; i++) {
        pq.push({nums[i][0], i});
    }
    for (int i = 0; i < k; i++) {
        auto [value, idx] = pq.top();
        pq.pop();
        ans[i] = value;
        int col = ++index[idx];
        if (col < nums[idx].size()) {
            pq.push({nums[idx][col], idx});
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> test {
        {10, 5, 4},
        {11, 3, 2},
        {9, 8, 7},
    };
    auto res = findtopk(test, 5);
    //println("{}", res);
    
}