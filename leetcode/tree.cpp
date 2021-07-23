#include "../etc/utils.h"

/*=======================================================================================
  leetcode 99. Recover Binary Search Tree
  BST中2个节点位置颠倒，找出并恢复
              3                          2
            /  \                       /  \
          1      4     =====>         1    4
               /                         /
              2                         3
*/
void recoverTree(TreeNode *root) {}

void code99() {
  TreeNode *root = new TreeNode(3);

  TreeNode *a = new TreeNode(1);
  TreeNode *b = new TreeNode(2);
  TreeNode *c = new TreeNode(4);
  root->left = a;
  root->right = c;
  c->left = b;
  recoverTree(root);
}
/*=======================================================================================
  leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal
  根据前序遍历与中序遍历重建二叉树
  preorder  = [9, 6, 4, 1, 2, 8, 11, 12, 7]
  inorder   = [1, 4, 2, 6, 8,9, 12, 11, 7]
  3种情形，vector<int>(v.begin(),v.end())
  begin()为起始位置,end()为终点后一点
*/
TreeNode *buildTreePre(vector<int> &preorder, vector<int> &inorder) {
  if (preorder.empty()) return nullptr;
  TreeNode *root = new TreeNode(preorder[0]);
  int n = preorder.size();
  if (n == 1) return root;
  int p = 0, l = 1;

  while (inorder[p] != preorder[0]) p++;
  if (p == 0) {
    /*左子树为空
    pre:1 2 3
    in :1 2 3
    */
    vector<int> prer(preorder.begin() + 1, preorder.end());
    vector<int> inr(inorder.begin() + 1, inorder.end());
    root->right = buildTreePre(prer, inr);
  } else if (p == n - 1) {
    /*右子树为空
    pre:1 2 3
    in :3 2 1
    */
    vector<int> prel(preorder.begin() + 1, preorder.end());
    vector<int> inl(inorder.begin(), inorder.end() - 1);
    root->left = buildTreePre(prel, inl);
  } else {
    vector<int> inl(inorder.begin(), inorder.begin() + p);
    while (find(inl.begin(), inl.end(), preorder[l]) != inl.end()) l++;
    l--;
    vector<int> prel(preorder.begin() + 1, preorder.begin() + l + 1);
    vector<int> prer(preorder.begin() + l + 1, preorder.end());
    vector<int> inr(inorder.begin() + p + 1, inorder.end());
    root->left = buildTreePre(prel, inl);
    root->right = buildTreePre(prer, inr);
  }

  return root;
}
void code105() {
  //   vector<int> pre = {9, 6, 4, 1, 2, 8, 11, 12, 7};
  //   vector<int> in = {1, 4, 2, 6, 8, 9, 12, 11, 7};
  //   vector<int> post = {1, 2, 4, 8, 6, 12, 7, 11, 9};
  vector<int> pre = {3, 2, 1, 4};
  vector<int> in = {1, 2, 3, 4};
  buildTreePre(pre, in);
}
/*=======================================================================================
    leetcode106. Construct Binary Tree from Inorder and Postorder Traversal
    根据后序遍历与中序遍历重建二叉树
    inorder   = [1, 4, 2, 6, 8,9(r), 12, 11, 7]         [1,4,2,6,8] r [12,11,7]~
    postorder = [1, 2, 4, 8, 6(p), 12, 7, 11, 9(r)]     [1,2,4,8,6] r [12,7,11]
    3种情形，vector<int>(v.begin(),v.end())

*/
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
  if (inorder.empty()) return nullptr;
  int n = inorder.size();
  TreeNode *root = new TreeNode(postorder[n - 1]);
  if (n == 1) return root;
  int r = 0;
  while (inorder[r] != postorder[n - 1]) r++;
  vector<int> inl(inorder.begin(), inorder.begin() + r);
  vector<int> postl(postorder.begin(), postorder.begin() + r);
  vector<int> inr(inorder.begin() + r + 1, inorder.end());
  vector<int> postr(postorder.begin() + r, postorder.end() - 1);
  root->left = buildTree(inl, postl);
  root->right = buildTree(inr, postr);
  return root;
}
void code106() {
  vector<int> in = {1, 4, 2, 6, 8, 9, 12, 11, 7};
  vector<int> post = {1, 2, 4, 8, 6, 12, 7, 11, 9};
  TreeNode *root = buildTree(in, post);
  cout << "";
}
/*=======================================================================================
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
//=======================================================================================
int main() {
  vector<int> a(100, 3);
  vector<int> b(a.end(), a.end());
  code106();
}