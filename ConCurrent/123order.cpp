#include <iostream>
#include <mutex>
#include <thread>

class FuncCaller {
public:
    static void call() {
        func1();
        func2();
        func3();
    }

private:
    static void func1() {
        std::call_once(flag1, [] {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Function 1 called" << std::endl;
        });
    }

    static void func2() {
        std::call_once(flag2, [] {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Function 2 called" << std::endl;
        });
    }

    static void func3() {
        std::call_once(flag3, [] {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Function 3 called" << std::endl;
        });
    }

    static std::once_flag flag1, flag2, flag3;
    static std::mutex mtx;
};

std::once_flag FuncCaller::flag1, FuncCaller::flag2, FuncCaller::flag3;
std::mutex FuncCaller::mtx;

int main() {
    std::thread t1(FuncCaller::call);
    std::thread t2(FuncCaller::call);
    std::thread t3(FuncCaller::call);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}