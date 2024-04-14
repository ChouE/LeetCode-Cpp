// 快速选择
/*
选择一个pivot，分割
根据分割后左右元素个数和k的大小关系，选择一边进行递归
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int partition(std::vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int i = left + 1, j = right;
    while (i <= j)
    {
        while (i <=j && nums[i] >= pivot) {
            i++;
        }
        while (i <= j && nums[j] < pivot) {
            j--;
        }
        if (i < j ) std::swap(nums[i], nums[j]);
    }
    std::swap(nums[left], nums[j]);
    return j;
}

void quickSelect(std::vector<int>& nums, int left, int right, int K) {
    if (left >= right )return;
    int p = partition(nums,left, right);
    if (p == K - 1) return;
    if (p < K - 1) {
        quickSelect(nums,p + 1, right, K);
    } else {
        quickSelect(nums, left, p - 1, K);
    }
}

std::vector<int> findTopK(std::vector<int>& nums, int K) {
    quickSelect(nums, 0, nums.size() - 1, K);
    return std::vector<int> (nums.begin(), nums.begin() + K);
}


int main() {
    std::vector<int> nums {3, 2, 1, 4, 6, 7};
    int K = 3;
    auto arr = findTopK(nums, K);
    for (auto i : arr) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    // 使用最小堆，使用于数据量未知的情况，如流式数据
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (auto num : nums) {
        pq.push(num);
        if (pq.size() > K) {
            pq.pop();
        }
    } 
    
    while (!pq.empty()) {
        std::cout << pq.top() << ' ';
        pq.pop();
    }
    std::cout << '\n';
    return 0;
}