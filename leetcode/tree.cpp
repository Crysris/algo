#include "../etc/utils.h"

/*
  leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal
  根据前序遍历与中序遍历重建二叉树
  Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
*/
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  if (preorder.empty()) return nullptr;
  TreeNode *root = new TreeNode(preorder[0]);
  int n = preorder.size();
  if (n == 1) return root;
  int p = 0, l = 0;

  while (inorder[p] != preorder[0]) p++;
  while (preorder[l] != inorder[p - 1]) l++;
  vector<int> prel(preorder.begin() + 1, preorder.begin() + l + 1);
  vector<int> inl(inorder.begin(), inorder.begin() + p);
  vector<int> prer(preorder.begin() + l + 1, preorder.end());
  vector<int> inr(inorder.begin() + p + 1, inorder.end());
  root->left = buildTree(prel, inl);
  root->right = buildTree(prer, inr);
  return root;
}
void code105() {
  // vector<int> pre = {1, 5, 2, 7, 4, 3, 9, 8, 6};
  // vector<int> in = {7, 2, 4, 5, 3, 1, 8, 9, 6};
  vector<int> pre = {1, 2, 3};
  vector<int> in = {2, 1, 3};
  buildTree(pre, in);
}
/*
  leetcode 572.Subtree of Another Tree
  验证一棵二叉树是否是另一棵数的子树

*/

bool isSameTree(TreeNode *a, TreeNode *b) {
  if (a == nullptr && b == nullptr) return true;
  if (a == nullptr || b == nullptr) return false;
  return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
}
bool isSubtree(TreeNode *root, TreeNode *subRoot) {
  if (isSameTree(root, subRoot)) return true;
  if (root != nullptr)
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  return false;
}

void code572() {}

int main() {
  vector<int> a(100, 3);
  vector<int> b(a.begin() + 1, a.begin() + 6);
  code105();
}