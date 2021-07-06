#include "RBNode.h"

#include "../etc/utils.h"

template <class T>
RBNode<T>::RBNode(T k, RBTCOLOR c) {
  key = k;
  color = c;
  left = nullptr;
  right = nullptr;
  parent = nullptr;
}

template <class T>
RBNode<T>::RBNode(T k, RBTCOLOR c, RBNode<T> *l, RBNode<T> *r, RBNode<T> *p) {
  key = l;
  color = c;
  left = l;
  right = r;
  parent = p;
}
