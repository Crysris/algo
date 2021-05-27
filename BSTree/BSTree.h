#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class BSNode {
 public:
  T key;
  BSNode<T> *left;
  BSNode<T> *right;
  BSNode(T k) : key(k), left(nullptr), right(nullptr) {}
  BSNode(T k, BSNode<T> *l, BSNode<T> *r) : key(k), left(l), right(r) {}
};

template <class T>
class BSTree {
 public:
  BSTree() : root(nullptr) {}
  ~BSTree();
  void destory(BSNode<T> *node);
  BSNode<T> *search(T k);
  bool insert(T k);
  bool remove(T k);
  void preOrder();
  void inOrder();
  void postOrder();
  void print() { inOrder(); }

 private:
  BSNode<T> *root;
  void inOrder(BSNode<T> *node);
  // void destory(BSNode<T> *node);
};
