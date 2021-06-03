//
//  main.cpp
//  algo
//
//  Created by 夏天的风 on 2021/6/3.
//

#include "BSTree/BSNode.cpp"
#include "BSTree/BSTree.cpp"

#define MAX_NODE_NUM 20
void quickSort() {}

int main(int argc, const char * argv[]) {
    auto *m_tree = new BSTree<int>();
    // BSNode<int> node(0);
    for (int i = 0; i <= MAX_NODE_NUM; i++) {
      m_tree->insert(i);
    }
    m_tree->print();

    // cout << " aa " << endl;
    return 0;
}
