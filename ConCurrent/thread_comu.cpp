#include <thread>
#include <iostream>
#include <future>


void compute(std::promise<int>&& p, int x) {
    int result = x * x;
    p.set_value(result);
}


int main() {
    int x = 9;
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::thread t(compute, std::move(p), x);
    int res = f.get();
    std::cout << "The square of " << x  << " is " << res << '\n';
    t.join();
    return 0;

}