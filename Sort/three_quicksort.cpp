#include <iostream>
#include <vector>
#include <random>

std::mt19937 gen(std::random_device{}());

template <typename T>
void quick_sort(T arr[], const int len) {
    if (len <= 1) return;
    std::uniform_int_distribution<> dis(0, len - 1);
    const T pivot = arr[dis(gen)];
    // i常规指针
    // j指向的是小于pivot的位置
    // k指向的是大于pivot的第一个位置
    int i = 0, j = 0, k = len;
    while (i < k) {
        if (arr[i] < pivot) {
            std::swap(arr[i++], arr[j++]);
        } else if (arr[i] > pivot) {
            // 换过来的这个值，并没有和pivot进行比较，因此i不能动
            std::swap(arr[i], arr[--k]);
        } else {
            i++;
        }
    }
    // left -> j 小于区
    quick_sort(arr, j);
    // arr + k 到 len 是大于区
    quick_sort(arr + k, len - k);
}

int main() {
    int a[] {3,5,1,2,6,7,3};
    quick_sort(a, 7);
    for (int t : a) {
        std::cout << t << ' ';
    }
}