//
// Created by 夏天的风 on 2021/5/29.
//
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "BSNode.h"

template <class T>
BSNode<T>::BSNode(T k) {
  key = k;
}
template <class T>
BSNode<T>::BSNode(T k, BSNode<T> *l, BSNode<T> *r) {
  key = k;
  left = l;
  right = r;
}

template <class T>
BSNode<T>::~BSNode() {
  delete left;
  delete right;
  delete this;
}