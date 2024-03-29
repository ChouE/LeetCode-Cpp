#include <chrono>
#include <thread>
#include <iostream>
#include <format>
#include <mutex>
#include <deque>
#include <condition_variable>

using namespace std::chrono_literals;
namespace this_thread = std::this_thread;
using guard_t = std::lock_guard<std::mutex>;
using lock_t = std::unique_lock<std::mutex>;

constexpr auto delay_time { 200ms };
constexpr size_t num_items { 10 };
// FIFO 队列
std::deque<size_t> q{};
std::mutex mtx {};
std::condition_variable cond {};
bool finished {};

void producer() {
    for (size_t i {}; i < num_items; i++) {
        this_thread::sleep_for(delay_time);
        guard_t x { mtx };
        q.push_back(i);
        cond.notify_all();
    }
    guard_t x { mtx };
    finished = true;
    cond.notify_all();
}

void consumer() {
    while (!finished) {
        lock_t lck { mtx };
        cond.wait(lck, [] {
            return !q.empty() || finished;
        });
        while (!q.empty())
        {   
            std::cout << std::format("Got {} from the queue\n", q.front());
            q.pop_front();
        }
        
    }
}

int main() {
    std::thread t1 { producer };
    std::thread t2 { consumer };
    std::thread t3 { consumer };
    t1.join();
    t2.join();
    t3.join();
    std::cout << "finished!\n";
}