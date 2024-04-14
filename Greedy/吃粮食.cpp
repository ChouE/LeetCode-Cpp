/**
 * @file 吃粮食.cpp
 * @author chouev
 * @brief 给定n个地点，一个长度为n的数组表示粮食售价
 * 求消耗最少的粮食，到达最终目的地
 * @version 0.1
 * @date 2024-04-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct Node {
    int idx, val, cnt;
    Node(int index, int value, int count ) : idx(index), val(value), cnt(count) {}

    bool operator< (const Node& other) const {
        if (val != other.val) {
            // 优先选择最小的价格
            return val > other.val;
        }
        if (cnt != other.cnt) {
            // 如果价格一样，选择被选择次数最少的
            return cnt > other.cnt;
        }
        // 否则随便选
        return idx < other.idx;
    }
};
int main() {
    // 输入n个数
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans(n, 0);
    // 输入售价数组
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    priority_queue<Node> heap;
    for (int i = 0; i < n - 1; i++) {
        heap.push(Node{i, arr[i], 0});
        Node top = heap.top();
        heap.pop();
        top.cnt++;
        ans[top.idx]++;
        // 重新放到队列中
        heap.push(top);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}