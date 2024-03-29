/**
 * 两个线程，从1开始到100，交替打印奇数和偶数
*/
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

std::mutex mtx;
std::condition_variable cv;

int cur = 1;
constexpr int target = 100;

void printOdd() {
    while (cur < target) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] {
            return cur % 2 != 0 || cur >= target;
        });
        if (cur >= target) return;
        std::cout << "Odd Thread: " << cur++ << '\n';
        
        lock.unlock();
        cv.notify_one();
    }
}

void printEven() {
    while (cur <= target) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] {
            return cur % 2 == 0 || cur > target;
        });
        if (cur > target) return;
        std::cout << "Even Thread: " << cur++ << '\n';
        
        lock.unlock();
        cv.notify_one();
    }
}

int main() {
    std::thread t1{printOdd};
    std::thread t2{printEven};

    t1.join();
    t2.join();

    return 0;

}