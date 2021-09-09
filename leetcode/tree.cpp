#include "../etc/utils.h"


template <class T>
void clearQueue(queue<T>& q) {
	queue<T> empty;
	swap(empty, q);
}

template <class T>
class LeetCodeTree{
public:
  TreeNode *root;
  int size;
  LeetCodeTree(){
    this->root=nullptr;
    this->size=0;
  }
  void print(){
    cout<<"size : "<<size<<endl;
    inOrder(root);
  }
  void inOrder(TreeNode *node){
    if (node == nullptr) return;
      inOrder(node->left);
      cout << node->val << " ";
      inOrder(node->right);
  }
  void insertByLevelNodes(vector<T> levelPrint){
    
    int n=levelPrint.size();
    if(n==0)return ;
    root=new TreeNode(levelPrint[0]);
    size=1;
    int numOfCurLevel=2;
    int count=1;
    int preStart=0,preEnd=0,curStart=1,curEnd=2;
    queue<TreeNode*>preNodes;
    queue<TreeNode*>curNodes;
    curNodes.push(root);
    while(curStart<n){
      preNodes=curNodes;
      clearQueue(curNodes);
      TreeNode *fatherNode;
      TreeNode *node;      
      int leftOrRight=0;
      for(int i=curStart;i<=curEnd;i++){
        fatherNode=preNodes.front();
        node=nullptr;
        if(levelPrint[i]!=0){
          size++;
          node=new TreeNode(levelPrint[i]);
          curNodes.push(node);
        }
        if(leftOrRight==0){
          fatherNode->left=node;
          leftOrRight=1;
        }
        else{
          fatherNode->right=node;
          leftOrRight=0;
          preNodes.pop();
        }
      }
      numOfCurLevel=2*curNodes.size();
      preStart=curStart;
      preEnd=curEnd;
      curStart=curEnd+1;
      curEnd=curEnd+numOfCurLevel;
    }
  }
  void dfs(){
    int ans=INT32_MIN;
    dfs(root,root,ans);

    cout<<ans<<endl;
  }
  int dfs(TreeNode *node,int &ans){
    if(node->left==nullptr&&node->right==nullptr){
      if(ans<node->val)ans=node->val;
      return node->val;
    }
    int leftMax=0;
    int rightMax=0;
    int curMax=node->val;
    if(node->left!=nullptr)leftMax=dfs(node->left,ans);
    if(node->right!=nullptr)rightMax=dfs(node->right,ans);
    if(leftMax+rightMax+node->val>ans){
      ans=leftMax+rightMax+node->val;
    }
    if(leftMax+node->val>curMax)curMax=leftMax+node->val;
    if(rightMax+node->val>curMax)curMax=rightMax+node->val;
    
    if(ans<curMax)ans=curMax;
    return curMax;
  }

};

void solve(){
  LeetCodeTree<int> m_tree;
  vector<int>levelPrint= {-10,9,20,0,0,15,7};
  m_tree.insertByLevelNodes(levelPrint);
  m_tree.dfs();
}



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
    leetcode107. Construct Binary Tree from Inorder and Postorder Traversal
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
void code107() {
  vector<int> in = {1, 4, 2, 6, 8, 9, 12, 11, 7};
  vector<int> post = {1, 2, 4, 8, 6, 12, 7, 11, 9};
  TreeNode *root = buildTree(in, post);
  cout << "";
}

/*=======================================================================================
    leetcode106. Binary Tree Maximum Path Sum
    

*/

int dfs(TreeNode *node,int &ans){
  if(node->left==nullptr&&node->right==nullptr){
    if(ans<node->val)ans=node->val;
    return node->val;
  }
  int leftMax=0;
  int rightMax=0;
  int curMax=node->val;
  if(node->left!=nullptr)leftMax=dfs(node->left,ans);
  if(node->right!=nullptr)rightMax=dfs(node->right,ans);
  if(leftMax+rightMax+node->val>ans){
    ans=leftMax+rightMax+node->val;
  }
  if(leftMax+node->val>curMax)curMax=leftMax+node->val;
  if(rightMax+node->val>curMax)curMax=rightMax+node->val;
  
  if(ans<curMax)ans=curMax;
  return curMax;
}
int maxPathSum(TreeNode* root) {
  int ans=INT32_MIN;
  dfs(root,ans);
  return ans;
}

void code106(){
}


/*=======================================================================================
  leetcode 112  Path Sum
  路径和等于指定值

*/
int pathSum(TreeNode *node){
  
}
bool hasPathSum(TreeNode* root, int targetSum) {
  if(root==nullptr)return false;
  if(targetSum==root->val&&root->left==nullptr&&root->right==nullptr)return true;
  targetSum=targetSum-root->val;
  return hasPathSum(root->left,targetSum)||hasPathSum(root->right,targetSum);
}
void code112(){

}


/*=======================================================================================
  leetcode 129. Sum Root to Leaf Numbers

  根到所有叶子的路径和

*/
void dfs(TreeNode* node,int pathNum,int &ans){
  if(node==nullptr)return ;
  pathNum=pathNum*10+node->val;
  if(node->left==nullptr&&node->right==nullptr){
    ans+=pathNum;
    return;
  }
  dfs(node->left,pathNum,ans);
  dfs(node->right,pathNum,ans);
}
int sumNumbers(TreeNode*   root) {
  int ans=0;
  dfs(root,0,ans);
  return ans;
}
//=======================================================================================


/*=======================================================================================
  leetcode 437. Path Sum III


*/
void dfs(TreeNode* node,int &ans,int targetSum){
  if(node->val==targetSum){
    ans++;
    return;
  }
  targetSum-=node->val;
  if(node->left)dfs(node->left,ans,targetSum);
  if(node->right)dfs(node->right,ans,targetSum);
}

int pathSum(TreeNode* root, int targetSum) {
  int ans=0;
  dfs()
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
  solve();
}