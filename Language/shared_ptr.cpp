#include <iostream>
/**
 * @brief 智能指针
 * 成员：裸指针、引用计数
 * 构造函数
 * 拷贝构造函数，引用计数的增加
 * 拷贝赋值函数，自赋值的判断，原引用的引用计数减少（如果为0，进行内存释放），更新指针和引用计数
 * 析构函数，减少引用计数，如果为0，进行内存释放
 * 操作符重载 * ->
 * use_count()返回引用计数
 */
class shareCounter {
 public:
  shareCounter() : count(1) {}
  void add() { ++count; }
  int release() { return --count; }
    size_t get_count() {return count;}
 private:
  size_t count;
};

template <typename T>
class SharedPointer {
 public:
    explicit SharedPointer(T* ptr = nullptr) : ptr_(ptr) {
        if (ptr_) {
            counter_ = new shareCounter();
        }
    }
    SharedPointer(const SharedPointer& other) : ptr_(other.ptr_), counter_(other.counter_) {
        if (ptr_) {
            counter_->add();
        }
    }
    ~SharedPointer() {
        if (ptr_ && counter_->release() == 0) {
            delete ptr_;
            delete counter_;
        }
    }
    SharedPointer& operator=(const SharedPointer& other) {
        if (this != &other) {
            if (ptr_ && counter_->release() == 0) {
                delete ptr_;
                delete counter_;
            }
            ptr_ = other.ptr_;
            counter_ = other.counter_;
            if (ptr_) {
                counter_->add();
            }
        }
        return *this;
    }
    T& operator*() const {
        return *ptr_;
    }
    T* operator->() const {
        return ptr_;
    }
    size_t use_count() {
        return counter_->get_count();
    }
 private:
  T* ptr_;
  shareCounter* counter_;
};

int main() {
    SharedPointer<int> ptr1(new int(10));
    SharedPointer<int> ptr2 = ptr1;
    std::cout << *ptr1 << '\n';
    std::cout << *ptr2 << '\n';
    std::cout << ptr1.use_count() << '\n';
    
    return 0;
}