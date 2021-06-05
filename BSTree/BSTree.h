#pragma once
#include "BSNode.h"

template <class T>
class BSTree {
 public:
    int size;
  BSTree();
  ~BSTree();
  void destory();
  BSNode<T> *search(T k);
  bool insert(T k);
  bool remove(T k);
  void preOrder();
  void inOrder();
  void postOrder();
  void print();

 private:
  BSNode<T> *root;
  void inOrder(BSNode<T> *node);
  void destory(BSNode<T> *node);
};
