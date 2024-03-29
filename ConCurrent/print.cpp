#include <condition_variable>
#include <iostream>
#include <mutex>
#include <print>
#include <thread>


std::mutex mu;
std::condition_variable cv;
int current = 1;

void printEven(int maxNum) {
  while (current <= maxNum) {
    std::unique_lock<std::mutex> lock(mu);
    cv.wait(lock, [] { return current % 2 == 1; });
    if (current > maxNum) {
      break;
    }
    std::print("Even num : {}\n", current);
    current++;
    lock.unlock();
    cv.notify_one();
  }
}

void printOdd(int maxNum) {
  while (current <= maxNum) {
    std::unique_lock<std::mutex> lock(mu);
    cv.wait(lock, []() { return current % 2 == 0; });
    if (current > maxNum) {
      break;
    }
    std::print("Odd num : {}\n", current);
    current++;
    lock.unlock();
    cv.notify_one();
  }
}

int main() {
  int maxNum = 221;
  std::jthread t1{printEven, maxNum};
  std::jthread t2{printOdd, maxNum};
}