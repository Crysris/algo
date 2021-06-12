//
// Created by 夏天的风 on 2021/5/29.
//

#include "BSNode.h"

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
template <class T>
BSNode<T>::BSNode(T k) {
  key = k;
  left = nullptr;
  right = nullptr;
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
