//#pragma once
#ifndef RBNODE_H
#define RBNODE_H

enum RBTCOLOR { RB_BLACK, RB_RED };

template <class T>
class RBNode {
 public:
  T key;
  RBTCOLOR color;
  RBNode<T> *left;
  RBNode<T> *right;
  RBNode<T> *parent;
  RBNode(T k, RBTCOLOR c);
  RBNode(T k, RBTCOLOR c, RBNode<T> *l, RBNode<T> *r, RBNode<T> *p);
};
#endif
