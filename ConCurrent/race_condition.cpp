#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>


class Timer {
  using tp = std::chrono::time_point<std::chrono::high_resolution_clock>;
  using dur_t = std::chrono::duration<double>;

private:
  tp start;
  tp end;
  dur_t duration;

public:
  Timer() : start(std::chrono::high_resolution_clock::now()) {}
  ~Timer() {
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << duration.count() << "s\n";
  }
};
std::atomic<long> at_num(0);

std::mutex mtx;
long num = 0;

void add_to_num() {
  for (int i = 0; i < 10000; i++) {
    std::lock_guard<std::mutex> lock(mtx);
    ++num;
  }
}

void add_atomic() {
  for (int i = 0; i < 10000; i++) {
    at_num.fetch_add(1, std::memory_order_relaxed);
  }
}
int main() {
  {
    std::vector<std::thread> threads;
    Timer t;
    for (int i = 0; i < 10; ++i) {
      threads.emplace_back(add_to_num);
    }
    for (auto &th : threads) {
      th.join();
    }
    std::cout << "ans : " << num << "\n";
  }
  {
    std::vector<std::thread> threads;
    Timer t;
    for (int i = 0; i < 10; ++i) {
      threads.emplace_back(add_atomic);
    }
    for (auto &th : threads) {
      th.join();
    }
    std::cout << "ans : " << num << "\n";
  }
  return 0;
}