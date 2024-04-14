#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

int calculate_max_energy(std::vector<int>& batteries) {
    int total = 0;
    std::sort(batteries.begin(), batteries.end(), std::greater<int>());
    while (batteries.size() >= 3) {
        bool found = false;
        for (auto i = batteries.begin(); i != batteries.end() && !found; ++i) {
            for (auto j = i + 1; j != batteries.end() && !found; ++j) {
                for (auto k = j + 1; k != batteries.end() && !found; ++k) {
                    int sum = *i + *j + *k;
                    if (sum % 4 == 0) {
                        total += std::pow(sum / 4 , 2);
                        batteries.erase(k);
                        batteries.erase(j);
                        batteries.erase(i);
                        found = true;
                    }
                }
            }
        }
        for (int& b : batteries) {
            if (b > 4) b--;
        }

    }
    return total;
}
int main() {
    std::vector<int> batteries(12);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(4, 16);
    for (int &battery : batteries) {
        battery = dis(gen);
    }
    for (auto b : batteries) {
        std::cout << b << " " ;
    }
    std::cout << '\n';

    int max_energy = calculate_max_energy(batteries);
    std::cout << max_energy << "\n";
    return 0;
}