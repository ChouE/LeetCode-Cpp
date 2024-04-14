#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int j = 0; j < n; j++) {
        while (!st.empty() && arr[j] > arr[st.top()]) {
            ans[st.top()] = j + 1; 
            st.pop();
        }
        st.push(j);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}