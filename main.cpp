#include "RBTree/RBTree.h"
#include "BSTree/BSTree.h"
void quickSort() {}

int main() {
  BSTree<int> *m_tree;
  for (int i = 0; i <= 20;i++){
    
    m_tree->insert(i);
  }
  m_tree->print();
  cout << " aa " << endl;
  return 0;
}