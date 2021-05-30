//#include "RBTree/RBTree.h"
#include "BSTree/BSNode.cpp"
#include "BSTree/BSTree.cpp"

#define MAX_NODE_NUM 20
void quickSort() {}

int main() {
  auto *m_tree = new BSTree<int>();
  // BSNode<int> node(0);
  for (int i = 0; i <= MAX_NODE_NUM; i++) {
    m_tree->insert(i);
  }
  m_tree->print();
  //delete m_tree;

  // cout << " aa " << endl;
  return 0;
}
