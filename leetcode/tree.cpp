#include "../etc/utils.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode *a, TreeNode *b) {
  if (a == nullptr && b == nullptr) return true;
  if (a == nullptr || b == nullptr) return false;
  return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
}
bool code572_isSubtree(TreeNode *root, TreeNode *subRoot) {
  if (isSameTree(root, subRoot)) return true;
  if (root != nullptr)
    return code572_isSubtree(root->left, subRoot) ||
           code572_isSubtree(root->right, subRoot);
  return false;
}

void code572_Subtree_of_Another_Tree() {}

int main() {}