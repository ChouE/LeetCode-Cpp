#include <iostream>

template <typename T>
class UniquePtr {
 private:
  T* ptr;

 public:
  explicit UniquePtr(T* p = nullptr) : ptr(p) {}
  // 禁止拷贝和拷贝赋值
  UniquePtr(const UniquePtr&) = delete;
  UniquePtr& operator=(const UniquePtr&) = delete;
  // 移动构造
  UniquePtr(UniquePtr&& other) : ptr(other.ptr) { other.ptr = nullptr; }
  // 移动赋值
  UniquePtr& operator=(UniquePtr&& other) {
    if (this != other) {
      delete ptr;
      ptr = other.ptr;
      other.ptr = nullptr;
    }
    return *this;
  }
  // 解引用
  T& operator*() const { return *ptr; }
  // 箭头
  T operator->() const { return ptr; }
  // get
  T* get() const {
    return ptr;
  }
  // release
  T* release() {
    T* old_ptr = ptr;
    ptr = nullptr;
    return old_ptr;
  }
  // reset
  void reset(T* p = nullptr) {
    T* old_ptr = ptr;
    ptr = p;
    if (old_ptr) {
        delete old_ptr;
    }
  }
  ~UniquePtr() {
    delete ptr;
  }
};

// make_uniqueptr
template<typename T, typename... Args>
UniquePtr<T> make_uniqueptr(Args&&...args) {
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}
int main() {
    UniquePtr<int> p(new int (10));
    std::cout << *p << '\n';
    // 移动
    UniquePtr<int> q = std::move(p);
    if (!p.get()) {
        std::cout << "p is null after move\n";
    }
    std::cout << *q << '\n';

    // reset 
    q.reset(new int(20));
    std::cout<< *q << '\n';

    auto t = make_uniqueptr<int>(60);
    std::cout << *t << '\n';
    return 0;
}