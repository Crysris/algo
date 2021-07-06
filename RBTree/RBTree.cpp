#include "RBTree.h"

template <class T>
RBTree<T>::RBTree() {
  size = 0;
  mRoot = nullptr;
}

template <class T>
RBTree<T>::RBTree(T k, RBTCOLOR c) {
  size = 0;
  mRoot = new RBNode<T>(k, c);
}

template <class T>
void RBTree<T>::insert(T k) {
  /*==============================    情景1   ==============================
  树为空，将插入节点置为根节点
  */
  if (mRoot == nullptr) {
    size = 1;
    mRoot = new RBNode<T>(k, RB_BLACK);
    return;
  }
  /*
     默认插入节点的颜色为红色
  */
  RBNode<T>* node = new RBNode<T>(k, RB_RED);
  insert(mRoot, node);
}

template <class T>
void RBTree<T>::insert(RBNode<T>* root, RBNode<T>* node) {
  RBNode<T>* temp = root;
  RBNode<T>* tempParent = root;
  while (temp != nullptr) {
    /*==============================    情景2   ==============================
      插入节点的key值已存在
    */
    if (node->key == temp->key) {
      return;

    } else if (node->key > temp->key) {
      tempParent = temp;
      temp = temp->right;
    } else {
      tempParent = temp;
      temp = temp->left;
    }
  }
  size++;
  /*==============================    情景3   ==============================
   插入节点的父节点为黑色
 */
  if (tempParent->color == RB_BLACK) {
    if (node->key > tempParent->key)
      tempParent->right = node;
    else
      tempParent->left = node;
    return;
  }

  // 叔叔节点存在
  RBNode<T>* uncle;
  if (tempParent->parent->left == tempParent) {
    uncle = tempParent->parent->right;
  } else
    uncle = tempParent->parent->left;
  /*==============================    情景4.1   ==============================
   插入节点的叔叔节点为红色
 */
  if (uncle->color == RB_RED) {
    tempParent->color = RB_BLACK;
    uncle->color = RB_BLACK;
    if(uncle->parent->parent==nullptr||uncle->parent->parent->color==RB_RED){

    }
    return;
  }
  
}
/*
  对p进行左旋，意味着"将p变成一个左节点"。

         pNode                           pNode
           |                                |
           p                                V
        /    \         ====>>            /    \
      F       V                         P       X
           /    \                     /   \
          R      X                   F     R
*/
template <class T>
void RBTree<T>::leftRotate(RBNode<T>* root, RBNode<T>* node) {
  RBNode<T>*pNode, *r, *v, *p;
  pNode = root;
  p = node;
  v = p->right;
  r = v->left;

  // pNode--v
  if (pNode->left == p)
    pNode->left = v;
  else
    pNode->right = v;
  v->parent = pNode;
  // v--p
  v->left = p;
  p->parent = v;
  // p--r
  p->right = r;
  r->parent = p;
}

template <class T>
void RBTree<T>::rightRotate(RBNode<T>* root, RBNode<T>* node) {}

template <class T>
RBNode<T>* RBTree<T>::search(T k) {
  return search(mRoot, k);
}
template <class T>
RBNode<T>* RBTree<T>::iterativeSearch(T k) {
  return iterativeSearch(mRoot, k);
}

template <class T>
RBNode<T>* RBTree<T>::search(RBNode<T>* node, T k) const {
  if (node == nullptr) return nullptr;
  if (k == node->key)
    return node;
  else if (k < node->key)
    return search(node->left, k);
  else
    return search(node->right, k);
}

template <class T>
RBNode<T>* RBTree<T>::iterativeSearch(RBNode<T>* node, T k) const {
  while (node != nullptr) {
    if (k == node->key)
      break;
    else if (k < node->key)
      node = node->left;
    else
      node = node->right;
  }
  return node;
}

template <class T>
void RBTree<T>::print() {
  print(mRoot);
}

template <class T>
void RBTree<T>::print(RBNode<T>* tree) {}

template <class T>
int RBTree<T>::getHeight() {
  return getHeight(mRoot);
}

template <class T>
int RBTree<T>::getHeight(RBNode<T>* tree) const {
  if (tree == nullptr) return 0;
  return 1 + max(getHeight(tree->left), getHeight(tree->right));
}

template <class T>
void RBTree<T>::preOrder() {
  cout << "PreOrder : " << endl;
  preOrder(mRoot);
  cout << endl << "size : " << size << endl;
}

template <class T>
void RBTree<T>::preOrder(RBNode<T>* tree) const {
  if (tree == nullptr) return;
  cout << tree->key << " ";
  preOrder(tree->left);
  preOrder(tree->right);
}

template <class T>
void RBTree<T>::inOrder() {
  cout << "InOrder : " << endl;
  inOrder(mRoot);
  cout << endl << "size : " << size << endl;
}

template <class T>
void RBTree<T>::inOrder(RBNode<T>* tree) const {
  if (tree == nullptr) return;
  inOrder(tree->left);
  cout << tree->key << " ";
  inOrder(tree->right);
}

template <class T>
void RBTree<T>::postOrder() {
  cout << "PostOrder : " << endl;
  postOrder(mRoot);
  cout << endl << "size : " << size << endl;
}

template <class T>
void RBTree<T>::postOrder(RBNode<T>* tree) const {
  if (tree == nullptr) return;
  postOrder(tree->left);
  postOrder(tree->right);
  cout << tree->key << " ";
}