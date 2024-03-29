#include <cassert>
#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <list>
#include <mutex>
#include <sstream>
#include <thread>
#include <vector>

std::mutex cout_mutex;
class TaskQueue {
 public:
  TaskQueue() = default;
  virtual ~TaskQueue() = default;
  virtual void enqueue(std::function<void()> fn) = 0;
  virtual void shutdown() = 0;
  virtual void on_idle() {}
};

class ThreadPool : public TaskQueue {
 public:
  explicit ThreadPool(size_t n) : shutdown_(false) {
    while (n) {
      threads_.emplace_back(worker(*this));
      n--;
    }
  }
  ThreadPool(const ThreadPool &) = delete;
  ~ThreadPool() override = default;

  void enqueue(std::function<void()> fn) override {
    std::unique_lock<std::mutex> lock(mutex_);
    jobs_.push_back(std::move(fn));
    cond_.notify_one();
  }
  void shutdown() override {
    {
      std::unique_lock<std::mutex> lock(mutex_);
      shutdown_ = true;
      cond_.notify_all();
    }
    for (auto &t : threads_) {
      t.join();
    }
  }

 private:
  struct worker {
    explicit worker(ThreadPool &pool) : pool_(pool) {}
    void operator()() {
      while (true) {
        std::function<void()> fn;
        {
          std::unique_lock<std::mutex> lock(pool_.mutex_);
          pool_.cond_.wait(
              lock, [&] { return !pool_.jobs_.empty() || pool_.shutdown_; });
          if (pool_.shutdown_ && pool_.jobs_.empty()) {
            break;
          }
          fn = pool_.jobs_.front();
          pool_.jobs_.pop_front();
        }
        assert(true == static_cast<bool>(fn));
        fn();
      }
    }
    ThreadPool &pool_;
  };
  std::mutex mutex_;
  std::condition_variable cond_;
  bool shutdown_;
  std::vector<std::thread> threads_;
  std::list<std::function<void()>> jobs_;
  friend struct worker;
};

int main() {
  ThreadPool pool(4);
  for (int i = 0; i < 10; i++) {
    pool.enqueue([i] {
        std::stringstream ss;
        ss << "Task" << i << " is running on thread "
                << std::this_thread::get_id() << std::endl;
      
      std::this_thread::sleep_for(std::chrono::microseconds(100));
      {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << ss.str();

      }

    });
  }
  pool.shutdown();
}