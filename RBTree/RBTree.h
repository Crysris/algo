//#pragma once
#ifndef RBTREE_H
#define RBTREE_H
#include "RBNode.cpp"
//#include "RBNode.h"
template <class T>
class RBTree {
 private:
  RBNode<T> *mRoot;

 public:
  int size;

 public:
  RBTree();
  RBTree(T k, RBTCOLOR c);
  RBTree(RBTree<T> *tree);
  ~RBTree();
  void insert(T k);
  void remove(T k);
  RBNode<T> *search(T k);
  // 非递归方式查找key为k的节点
  RBNode<T> *iterativeSearch(T k);
  // 返回最大节点的key
  T maximun();
  // 返回最小节点的key
  T minimun();
  // 后继节点，即红黑树中数值大于node的最小节点
  RBNode<T> *successor(RBNode<T> *node);
  // 前驱节点，即红黑树中数值小于node的最大节点
  RBNode<T> *predecessor(RBNode<T> *node);
  // 返回的树的高
  int getHeight();

  // 销毁整棵树
  void destory();

  void print();
  void preOrder();
  void inOrder();
  void postOrder();

  void levelOrder();

 private:
  RBNode<T> *search(RBNode<T> *node, T k) const;
  RBNode<T> *iterativeSearch(RBNode<T> *node, T k) const;

  // 返回以tree为根节点的红黑树的最大节点
  RBNode<T> *maximun(RBNode<T> *tree);
  // 返回以tree为根节点的红黑树的最小节点
  RBNode<T> *minimun(RBNode<T> *tree);

  void leftRotate(RBNode<T> *&root, RBNode<T> *node);
  void rightRotate(RBNode<T> *&root, RBNode<T> *node);

  void insert(RBNode<T> *&root, RBNode<T> *node);
  // 插入修正函数
  void insertFixUp(RBNode<T> *&root, RBNode<T> *node);

  void remove(RBNode<T> *&root, RBNode<T> *node);
  // 删除修正函数
  void removeFixUp(RBNode<T> *&root, RBNode<T> *node, RBNode<T> *father_node);
  // 回以tree为根节点的红黑树的高
  int getHeight(RBNode<T> *tree) const;

  void preOrder(RBNode<T> *tree) const;
  void inOrder(RBNode<T> *tree) const;
  void postOrder(RBNode<T> *tree) const;
  void levelOrder(RBNode<T> *tree) const;
  void print(RBNode<T> *tree);
  void destory(RBNode<T> *&tree);

  //#define setColor(node, c) (n->color = c)
};

#endif
