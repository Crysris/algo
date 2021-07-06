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
  if (mRoot == nullptr) {
    size = 1;
    mRoot = new RBNode<T>(k, RB_BLACK);
    return;
  }
  RBNode<T>* node = new RBNode<T>(k, RB_RED);
  insert(mRoot, node);
}

template <class T>
void RBTree<T>::insert(RBNode<T>* root, RBNode<T>* node) {
  RBNode<T>* temp = root;
  RBNode<T>* tempParent = root;
  while (temp != nullptr) {
    if (node->key == temp->key)
      return;
    else if (node->key > temp->key) {
      tempParent = temp;
      temp = temp->right;
    } else {
      tempParent = temp;
      temp = temp->left;
    }
  }
  size++;
  if (node->key > tempParent->key)
    tempParent->right = node;
  else
    tempParent->left = node;
}
/*
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