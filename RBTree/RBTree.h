#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum RBTCOLOR { BLACK, RED };
template <class T>
class RBNode {
 public:
  T key;
  RBTCOLOR color;
  RBNode<T> *left;
  RBNode<T> *right;
  RBNode<T> *parent;

  RBNode(T k, RBTCOLOR c)
      : key(k), color(c), parent(nullptr), left(nullptr), right(nullptr) {}
  RBNode()
      : key(0), color(BLACK), parent(nullptr), left(nullptr), right(nullptr) {}
  RBNode(T k, RBTCOLOR c, RBNode<T> *p, RBNode<T> *l, RBNode<T> *r)
      : key(k), color(c), parent(p), left(l), right(r) {}
};

template <class T>
class RBTree {
 private:
  RBNode<T> *root;

 public:
  RBTree();
  RBTree(T k, RBTCOLOR c);
  RBTree(RBTree<T> *t);
};