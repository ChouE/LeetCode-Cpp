#include <iostream>
#include <vector> 
#include <random>

// 随机快速排序是一种优化
// 可以避免一些极端情况

int partition(std::vector<int>& arr, int left ,int right) {
    int pivot = arr[right];

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

int randomPartition(std::vector<int>& arr, int left, int right) {
    // 随机数生成器
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(left, right);

    // 选择一个位置
    int randomIndex = dis(gen);

    // 与右端的元素进行交换
    std::swap(arr[randomIndex], arr[right]);

    return partition(arr, left, right);
}

void randomQuickSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = randomPartition(arr, left, right);
        randomQuickSort(arr, left, pivotIndex - 1);
        randomQuickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    std::vector<int> arr {1,4,-2,4,7,2,6,90,32,55,1234,41,45};
    std::cout << "Original Array: ";
    std::for_each(arr.begin(),arr.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << '\n';
    randomQuickSort(arr, 0, arr.size() - 1);
    std::cout << "Sorted Array: ";
    std::for_each(arr.begin(),arr.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << '\n';

    return 0;
}


