// 智能指针实现
#include <atomic>
#include <exception>

template <typename T>
class SmartPtr {
private:
    T* ptr;
    std::atomic<int>* use_count;
public:
    // 构造函数
    SmartPtr(T* p) : ptr(p) {
        if (!ptr) throw std::exception();
        use_count = new atomic<int>(1);
    }
    // 析构函数
    ~SmartPtr() {
        (*use_count)--;
        if (*use_count == 0) {
            delete ptr;
            delete use_count;
        }
    }
    // 拷贝构造函数
    SmartPtr(const SmartPtr& sp) {
        ptr = sp.ptr;
        use_count = sp.use_count;
        (*use_count)++;
    }
    // 拷贝赋值运算符
    SmartPtr& operator=(const SmartPtr& sp) {
        // 自赋值情况
        if (this == &sp) return *this;
        // 赋值之后原来的使用权丢失，引用计数-1
        // 如果-1后为0，释放资源
        (*use_count)--;
        if (*use_count == 0) {
            delete ptr;
            delete use_count;
        }
        // 获取新的资源
        ptr = sp.ptr;
        use_count = sp.use_count;
        (*use_count)++;
        return *this;
    }
    T& operator*() {
        return *ptr;
    }
    T* operator->() {
        return ptr;
    }
    int get_count() {
        return *use_count;
    }
};