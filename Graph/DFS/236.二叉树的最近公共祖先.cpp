/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        // 满足两个条件之一
        // 第一个是左右子树都有p和q
        // 第二个是当前节点是p或者q，而且左右子树中有一个有另外一个
        if ( lson && rson || ((root->val == p->val || root->val == q->val) && (lson || rson)) ) {
            ans = root;
        }
        // 满足任意一个条件，返回true
        return lson || rson || root->val == p->val || root->val == q->val;
    }
    TreeNode* ans;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
// @lc code=end

