#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;
  TreeNode() = default;
  TreeNode(int x) : val(x) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(val), left(left), right(right) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  std::queue<TreeNode*> q;
  std::vector<std::vector<int>> ans;
  if (!root) {
    return ans;
  }
  q.push(root);
  while (!q.empty()) {
    int n = q.size();
    ans.push_back(std::vector<int>());
    for (int i = 0; i < n; i++) {
      auto node = q.front();
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
      q.pop();
      ans.back().push_back(node->val);
    }
  }
  return ans;
}
TreeNode* buildTree(const std::vector<int>& data) {
  if (data.empty()) {
    return nullptr;
  }
  std::queue<TreeNode*> queue;
  TreeNode* root = new TreeNode(data[0]);
  queue.push(root);
  int i = 1;
  while (!queue.empty() && i < data.size()) {
    TreeNode* node = queue.front();
    queue.pop();
    if (i < data.size() && data[i] != INT_MIN) {
      node->left = new TreeNode(data[i]);
      queue.push(node->left);
    }
    i++;
    if (i < data.size() && data[i] != INT_MIN) {
        node->right = new TreeNode(data[i]);
        queue.push(node->right);
    }
    i++;
  }
  return root;
}

void deleteTree(TreeNode* node) {
    if (node ==  nullptr) return;
    delete(node->left);
    delete(node->right);
    delete node;
}
int main() {
    std::vector<int> data {3, 9 ,20 ,INT_MIN, INT_MIN, 15, 7};
    TreeNode* root = buildTree(data);
    auto ans = levelOrder(root);
    for (auto &a : ans) {
        for(auto i : a) {
            std::cout << i << " ";
        }
        std::cout << '\n';
    }

    // delete
    deleteTree(root);
    root = nullptr;
    return 0;
}