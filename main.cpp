//
//  main.cpp
//  algo
//
//  Created by 夏天的风 on 2021/6/3.
//

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#include "BSTree/BSNode.cpp"
#include "BSTree/BSTree.cpp"
#define MAX_NODE_NUM 50
void quickSort() {}

int main(int argc, const char *argv[]) {
  auto *m_tree = new BSTree<int>();
  // BSNode<int> node(0);
  unordered_set<int> m_set;
  unordered_set<int>::iterator iter;
  srand((int)time(nullptr));
  int num;
  while (m_set.size() < MAX_NODE_NUM) {
    // [0,MAX_NODE_NUM)
    num = rand() % MAX_NODE_NUM;
    iter = m_set.find(num);
      if (iter == m_set.end()) {
          m_tree->insert(num);
          m_set.insert(num);
          cout<<"new value inserted :"<<num<<" size : "<<m_tree->size<<endl;
          

      }
  }
    cout<<"size : "<<m_tree->size<<endl;
  m_tree->print();

  // cout << " aa " << endl;
    
  return 0;
}
