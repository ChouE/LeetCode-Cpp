#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <execution>
using dur_t = std::chrono::duration<double>;
class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    dur_t duration;
public:
    Timer() : start(std::chrono::high_resolution_clock::now()) {}
    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "Time: " << duration.count() << " seconds\n";
    }
};
int main()
{
    std::vector<unsigned> v(10 * 1000 * 1000);

    std::random_device rd;
    for (auto &i : v)
        i = rd() % 0xFFFF;
    auto mul2 = [](int n)
    { return n * 2; };
    {
        Timer t;
        std::transform(v.begin(), v.end(), v.begin(), mul2);
    }
    {
        Timer t;
        std::transform(std::execution::par, v.begin(), v.end(), v.begin(), mul2);
    }
    {
        Timer t;
        std::transform(std::execution::par_unseq, v.begin(), v.end(), v.begin(), mul2);
    }
    return 0;
}