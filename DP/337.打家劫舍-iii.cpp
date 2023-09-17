/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    // f表示选择该节点，子树上被选择的最大值
    // g表示不选择该节点，子树上被选择的最大值
    unordered_map<TreeNode*, int> f, g;

    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        // 选择该节点，那么子节点就不能选
        f[node] = node->val + g[node->left] + g[node->right];
        // 不选择该节点，那么子节点可以选，也可以不选
        g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right
        ]);
    }
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
};
// @lc code=end

