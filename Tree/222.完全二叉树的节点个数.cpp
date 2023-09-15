/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        // 计算树高
        int level = 0; 
        TreeNode* node = root;
        while (node->left != nullptr) 
        {
            level++;
            node = node->left;
        }
        // 二分查找节点个数
        // low = 2^level，high = 2^(level + 1) - 1
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            // 存在则low = mid，不存在则high = mid - 1
            if (exists(root, level, mid)) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
    // 判断第k个节点是否存在
    bool exists(TreeNode* root, int level, int k) {
        // bits = 1000...，level = 3，k = 6
        int bits = 1 << (level - 1);
        TreeNode* node = root;
        // 从根节点的第二位开始判断
        while (node != nullptr && bits > 0) {
            if (!(bits & k)) {
                node = node->left;
            }
            else {
                node = node->right;
            }
            bits >>= 1;
        }
        // node != nullptr，说明第k个节点存在
        return node != nullptr;
    }
};
// @lc code=end

