#include <chrono>
#include <iostream>
#include <future>
#include <list>
#include <format>
struct prime_time
{
    std::chrono::duration<double> dur {};
    uint64_t count {};
};

prime_time count_primes(const uint64_t max) {
    prime_time ret{};
    constexpr auto isprime = [](const uint64_t n) {
        if (n < 2) return false;
        if (n < 4) return true;
        if (n % 2 == 0) return false;
        for (uint64_t i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    };
    uint64_t start = {2};
    uint64_t end {max};
    auto t1 = std::chrono::high_resolution_clock::now();
    for (uint64_t i {start}; i <= end; i++) {
        if (isprime(i)) ++ret.count;
    }
    ret.dur = std::chrono::high_resolution_clock::now() - t1;
    return ret;
}

int main() {
    constexpr uint64_t max = 1000000;
    std::list<std::future<prime_time>> swarm;
    std::cout << "Starting\n";
    auto t1 {std::chrono::high_resolution_clock::now()};
    for (size_t i {}; i < 15; ++i) {
        swarm.emplace_back(std::async(std::launch::async, count_primes, max));
    }
    for (auto &f : swarm) {
        static size_t i{};
        auto pt = f.get();
        std::cout << std::format("Thread {} found {} primes in {} secondes\n", i++, pt.count, pt.dur.count());
    }
    auto t2 {std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> dur = t2 - t1;
    std::cout << std::format("Total time: {:.5f} seconds\n", dur.count());
    return 0;
}
