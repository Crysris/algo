//
//  main.cpp
//  algo
//
//  Created by 夏天的风 on 2021/6/3.
//

#include "RBTree/RBTree.cpp"

#define MAX_NODE_NUM 50

/*
 if root==nullptr ,treeHeight=0;
 每一层节点数目： 1,2,4,8.....  ，第k层：2^(k-1)
 每一层启始坐标：......8,4,2,1  ，第k层，2^(n-k)

*/
void printTree(int treeHeight = 3) {}

int main(int argc, const char *argv[]) {
  auto *m_tree = new RBTree<int>();
  // BSNode<int> node(0);
  unordered_set<int> m_set;
  unordered_set<int>::iterator iter;
  srand((int)time(nullptr));
  int num;

  int count = 0;
  while (m_set.size() < MAX_NODE_NUM) {
    // [0,MAX_NODE_NUM)

    num = rand() % MAX_NODE_NUM;
    iter = m_set.find(num);
    if (iter == m_set.end()) {
      m_tree->insert(num);
      m_set.insert(num);
      cout << "new value inserted :" << num << " size : " << m_tree->size
           << " height : " << m_tree->getHeight() << " count : " << count
           << endl;
    }
    count++;
  }
  m_tree->inOrder();
  return 0;
}