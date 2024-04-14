#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <numbers>

struct Point {
    double x, y;
};

std::vector<Point> generateMonsters(int count, double radius) {
    std::vector<Point> monsters;
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<> dis(0, 1);
    for (int i = 0; i < count; i++) {
        double r = std::sqrt(dis(gen))* radius;
        double theta = dis(gen) * 2 * std::numbers::pi;
        Point p {r * std::cos(theta), r * std::sin(theta)};
        monsters.push_back(p);
    }
    return monsters;
}

int main() {
    int count = 100;
    double radius = 10.0;
    std::vector<Point> monsters = generateMonsters(count, radius);
    for (const Point& p : monsters) {
        std::cout << "Monsters at (" << p.x << "," << p.y << ")\n";
    }
    return 0;
}