/**
 * @file shuffle.cpp
 * @author chouev
 * @brief 一副牌54张，随机分配给4个玩家
 * @version 0.1
 * @date 2024-04-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include <print>

// shuffle
void shuffleDeck(std::vector<int>& deck){ 
    std::mt19937 rng(std::random_device{}());
    for (int i = deck.size() - 1; i > 0; i--) {
        std::uniform_int_distribution<> dis(0, i);
        // 生成一个[0,i]的随机索引
        int j = dis(rng);
        // 与当前元素进行交换
        std::swap(deck[i], deck[j]);
    }
}

int main() {
    // 52 cards
    std::vector<int> deck(52);
    std::iota(deck.begin(), deck.end(), 1);
    shuffleDeck(deck);
    std::vector<int> players[4];
    for (int i = 0; i < 52; i++) {
        players[i % 4].push_back(deck[i]);
    }
    for (int i = 0; i < 4; i++) {
        std::print("Player {:>2}: ", i + 1);
        //std::cout << "Player " << i + 1 << ": ";
        for (int card : players[i]) {
            std::print("{:>2} ", card);
            //std::cout << card << " ";
        }
        std::cout << '\n';
    }
    return 0;
}