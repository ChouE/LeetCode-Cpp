/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) {
      return res;
    }
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()) {
        auto node = stk.top();
        stk.pop();
        if (node) {
            res.push_back(node->val);
            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }
    }
    return res;
  }
};
// @lc code=end
