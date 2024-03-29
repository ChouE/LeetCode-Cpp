#include <iostream>
#include <memory>
#include <vector>

template <typename T>
class TreeNode {
 public:
  T val;
  std::unique_ptr<TreeNode<T>> left;
  std::unique_ptr<TreeNode<T>> right;

  TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
};

template <typename T>
void PreorderTraversal(const TreeNode<T>* node) {
  if (node != nullptr) {
    std::cout << node->val << " ";
    PreorderTraversal(node->left.get());
    PreorderTraversal(node->right.get());
  }
}

template <typename T>
std::unique_ptr<TreeNode<T>> BuildTree(const std::vector<T>& values,
                                       int index) {
  if (index >= values.size() ||
      values[index] == -1)  // Assuming -1 represents null.
    return nullptr;

  auto node = std::make_unique<TreeNode<T>>(values[index]);
  node->left = BuildTree(values, 2 * index + 1);
  node->right = BuildTree(values, 2 * index + 2);

  return node;
}

int main() {
  // 创建二叉树的节点
  std::vector<int> values = {1, 2, 3, -1, -1, 4, 5};  // -1 表示空节点
  auto root = BuildTree(values, 0);

  // 执行先序遍历
  PreorderTraversal(root.get());
  return 0;
}