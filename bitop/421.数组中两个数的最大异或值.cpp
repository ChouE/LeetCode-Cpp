/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
// 释放空间会超时
struct Trie
{
    /* data */
    shared_ptr<Trie> left;
    shared_ptr<Trie> right;
    // ~Trie() {
    //     left.reset();
    //     right.reset();
    // }   
};
using TrieNode = shared_ptr<Trie>;

class Solution {
private:
    TrieNode root = make_shared<Trie>();
    static constexpr int HIGH_BIT = 30;
public:
    void add(int num) {
        TrieNode cur = root;
        for (int k = HIGH_BIT; k >= 0; k--) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                if (!cur->left) {
                    cur->left = make_shared<Trie>();
                }
                cur = cur->left;
            } else {
                if (!cur->right) {
                    cur->right = make_shared<Trie>();
                }
                cur = cur->right;
            }
        }
    }

    int check(int num) {
        TrieNode cur = root;
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; k--) {
            // 从高位到低位
            int bit = (num >> k) & 1;
            if (bit == 0) {
                if (cur->right) {
                    cur = cur->right;
                    x = x * 2 + 1;
                } else {
                    cur = cur->left;
                    x = x * 2;
                }
            } else {
                if (cur->left) {
                    cur = cur->left;
                    x = x * 2 + 1;
                } else {
                    cur = cur->right;
                    x = x * 2;
                }
            }
        }
        return x;
    }
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 1; i < n; i++) {
            add(nums[i - 1]);
            x = max(x, check(nums[i]));
        }
        return x;
    }
};
// @lc code=end

