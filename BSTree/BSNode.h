//
// Created by 夏天的风 on 2021/5/29.
//
//#pragma once
#ifndef BSNODE_H
#define BSNODE_H

template <class T>
class BSNode {
 public:
  T key;
  BSNode<T> *left;
  BSNode<T> *right;
  explicit BSNode(T k);
  BSNode(T k, BSNode<T> *l, BSNode<T> *r);
  ~BSNode();
};
#endif