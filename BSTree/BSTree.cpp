#include "BSTree.h"

template <class T>
BSTree<T>::BSTree() {
  root = nullptr;
}
template <class T>
BSTree<T>::~BSTree() {
  destory(root);
}
template <class T>
BSNode<T> *BSTree<T>::search(T k) {
  BSNode<T> *p = root;
  while (p != nullptr) {
    if (p->key == k) break;
    if (p->key < k)
      p = p->left;
    else
      p = p->right;
  }
  return p;
}

template <class T>
bool BSTree<T>::insert(T k) {
  if (root == nullptr) {
    root = new BSNode<T>(k);
    return true;
  }
  BSNode<T> *p = root;
    BSNode<T> *q=p;
  while (p != nullptr) {
    if (p->key == k)
      return false;
    else if (p->key < k) {
      q = p;
      p = p->right;
    } else {
      q = p;
      p = p->left;
    }
  }
  BSNode<T> *r = new BSNode<T>(k);
  if (q->key < k)
    q->right = r;
  else
    q->left = r;
  return true;
}

template <class T>
void BSTree<T>::inOrder() {
  if (root == nullptr) return;
  inOrder(root);
}

template <class T>
void BSTree<T>::print() {
  inOrder();
}
template <class T>
void BSTree<T>::inOrder(BSNode<T> *node) {
  if (node == nullptr) return;
  inOrder(node->left);
  cout << node->key << " ";
  inOrder(node->right);
}

template <class T>
void BSTree<T>::destory() {
  destory(root);
}

template <class T>
void BSTree<T>::destory(BSNode<T> *node) {
  if (node == nullptr) return;
  destory(node->left);
  destory(node->right);
  delete node;
}
