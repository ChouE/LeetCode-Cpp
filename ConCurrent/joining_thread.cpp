// 析构时自动join
#include <iostream>
#include <print>
#include <thread>

class joining_thread {
 private:
  std::thread t;

 public:
  joining_thread() noexcept = default;
  // 接收任意Callable和任意参数的构造函数
  template <typename Callable, typename... Args>
  explicit joining_thread(Callable&& func, Args&&... args)
      : t{std::forward<Callable>(func), std::forward<Args>(args)...} {}
  explicit joining_thread(std::thread t) noexcept : t{std::move(t)} {}
  joining_thread(joining_thread&& other) noexcept : t{std::move(other.t)} {}

  joining_thread& operator=(std::thread&& other) noexcept {
    // 先执行完自己的
    if (joinable()) {
      join();
    }
    // 拿过来
    t = std::move(other);
    return *this;
  }

  ~joining_thread() {
    if (joinable()) {
      join();
    }
  }
  void swap(joining_thread& other) { t.swap(other.t); }
  std::thread::id get_id() const noexcept { return t.get_id(); }
  bool joinable() const noexcept { return t.joinable(); }
  void join() { t.join(); }
  void detach() { t.detach(); }
  std::thread& data() noexcept { return t; }
  const std::thread& data() const noexcept { return t; }
};

int main() {
  std::print("{}\n", std::this_thread::get_id());
  joining_thread thread{
      []() { std::print("{}\n", std::this_thread::get_id()); }};
  joining_thread thread2 { std::move(thread) };
  return 0;
}