#include "RBTree.h"

template <class T>
RBTree<T>::RBTree() {
  size = 0;
  mRoot = nullptr;
}

template <class T>
RBTree<T>::RBTree(T k, RBTCOLOR c) {
  size = 0;
  mRoot = new RBNode<T>(k, c);
}

template <class T>
void RBTree<T>::insert(T k) {
  /*==============================    情景1   ==============================
  树为空，将插入节点置为根节点
  */
  if (mRoot == nullptr) {
    size = 1;
    mRoot = new RBNode<T>(k, RB_BLACK);
    return;
  }
  /*
     默认插入节点的颜色为红色
  */
  RBNode<T>* node = new RBNode<T>(k, RB_RED);
  insert(mRoot, node);
}

template <class T>
void RBTree<T>::insert(RBNode<T>*& root, RBNode<T>* node) {
  RBNode<T>* temp = root;
  RBNode<T>* tempParent = root;
  while (temp != nullptr) {
    /*==============================    情景2   ==============================
      插入节点的key值已存在
    */
    if (node->key == temp->key) {
      return;

    } else if (node->key > temp->key) {
      tempParent = temp;
      temp = temp->right;
    } else {
      tempParent = temp;
      temp = temp->left;
    }
  }
  size++;
  if (node->key > tempParent->key)
    tempParent->right = node;
  else
    tempParent->left = node;
  node->parent = tempParent;
  /*==============================    情景3   ==============================
   插入节点的父节点为黑色
 */
  if (tempParent->color == RB_BLACK) return;

  insertFixUp(root, node);
}

/*
  插入修正函数，在插入之后使用，使红黑树恢复平衡
  应用于情景4.1，4.2，4.3
*/
template <class T>
void RBTree<T>::insertFixUp(RBNode<T>*& root, RBNode<T>* node) {
  RBNode<T>*father_node, *grandfa_node, *uncle;
  RBNode<T>* current_node = node;
  // 叔叔节点存在

  while (true) {
    // 插入节点的父节点为空，或者为黑色，则不需要修正
    if (current_node->parent == nullptr ||
        current_node->parent->color == RB_BLACK)
      break;
    father_node = current_node->parent;
    grandfa_node = father_node->parent;
    if (grandfa_node) {
      if (father_node == grandfa_node->left)
        uncle = grandfa_node->right;
      else
        uncle = grandfa_node->left;
      if (uncle) {
        if (uncle->color == RB_RED) {
          /*============================== 情景4.1==============================
            插入节点的叔叔节点为红色
          */
          father_node->color = RB_BLACK;
          uncle->color = RB_BLACK;
          grandfa_node->color = RB_RED;
          current_node = grandfa_node;
        } else {
          if (father_node == grandfa_node->left) {
            /*==============================情景4.2==============================
              插入节点的叔叔节点为黑色或空，且插入节点的父节点使祖父节点的左子节点
            */
            if (current_node == father_node->left) {
              /*情景4.2.1
               插入节点是父节点的左子节点
              */
              rightRotate(root, grandfa_node);
              grandfa_node->color = RB_RED;
              father_node->color = RB_BLACK;
            } else {
              /*情景4.2.2
               插入节点是父节点的右子节点
              */
              swap(current_node, father_node);
              leftRotate(root, current_node);
            }
          } else {
            /*==============================情景4.3==============================
              插入节点的叔叔节点为黑色或空，且插入节点的父节点使祖父节点的右子节点
            */
            if (current_node == father_node->left) {
              /*情景4.3.1
                插入节点是父节点的左子节点
              */
              swap(father_node, current_node);
              rightRotate(root, current_node);
            } else {
              /*情景4.3.2
                插入节点是父节点的右子节点
              */
              leftRotate(root, grandfa_node);
              grandfa_node->color = RB_RED;
              father_node->color = RB_BLACK;
            }
          }
        }
      } else {
        if (father_node == grandfa_node->left) {
          /*==============================情景4.2==============================
            插入节点的叔叔节点为黑色或空，且插入节点的父节点使祖父节点的左子节点
          */
          if (current_node == father_node->left) {
            /*情景4.2.1
             插入节点是父节点的左子节点
            */
            rightRotate(root, grandfa_node);
            grandfa_node->color = RB_RED;
            father_node->color = RB_BLACK;
          } else {
            /*情景4.2.2
             插入节点是父节点的右子节点
            */
            swap(father_node, current_node);
            leftRotate(root, current_node);
          }
        } else {
          /*==============================情景4.3==============================
            插入节点的叔叔节点为黑色或空，且插入节点的父节点使祖父节点的右子节点
          */
          if (current_node == father_node->left) {
            /*情景4.3.1
              插入节点是父节点的左子节点
            */
            swap(father_node, current_node);
            rightRotate(root, current_node);
          } else {
            /*情景4.3.2
              插入节点是父节点的右子节点
            */
            leftRotate(root, grandfa_node);
            grandfa_node->color = RB_RED;
            father_node->color = RB_BLACK;
          }
        }
      }
    }
  }
  /*
    如果当前节点为根节点，则直接置为黑色
  */
  root->color = RB_BLACK;
}

/*

  对p进行左旋，意味着"将p变成一个左节点"
  P,F一定不为空

         pNode                           pNode
           |                                |
           p                                V
        /    \         ====>>            /    \
      F       V                         P       X
           /    \                     /   \
          R      X                   F     R
*/
template <class T>
void RBTree<T>::leftRotate(RBNode<T>*& root, RBNode<T>* node) {
  RBNode<T>*pNode, *r, *v, *p;
  pNode = node->parent;
  p = node;
  v = p->right;
  r = v->left;
  // p--r
  p->right = r;
  if (r != nullptr) r->parent = p;
  // v--p
  v->left = p;
  p->parent = v;
  // pNode--v
  v->parent = pNode;
  if (pNode == nullptr) {
    root = v;
  } else {
    if (pNode->left == p)
      pNode->left = v;
    else
      pNode->right = v;
  }
}
/*
  对p进行右旋，意味着"将p变成一个右节点"
  P,F一定不为空
         pNode                           pNode
           |                                |
           p                                F
        /    \         ====>>            /    \
      F       V                         R      p
   /    \                                     / \
  R      X                                   X   V
*/
template <class T>
void RBTree<T>::rightRotate(RBNode<T>*& root, RBNode<T>* node) {
  RBNode<T>*pNode, *p, *f, *x;
  pNode = node->parent;
  p = node;
  f = p->left;
  x = f->right;
  // p--x
  p->left = x;
  if (x != nullptr) x->parent = p;
  // f--p
  f->right = p;
  p->parent = f;
  // pNode--f
  f->parent = pNode;
  if (pNode == nullptr) {
    root = f;
  } else {
    if (pNode->left == p)
      pNode->left = f;
    else
      pNode->right = f;
  }
}

template <class T>
RBNode<T>* RBTree<T>::search(T k) {
  return search(mRoot, k);
}
template <class T>
RBNode<T>* RBTree<T>::iterativeSearch(T k) {
  return iterativeSearch(mRoot, k);
}

template <class T>
RBNode<T>* RBTree<T>::search(RBNode<T>* node, T k) const {
  if (node == nullptr) return nullptr;
  if (k == node->key)
    return node;
  else if (k < node->key)
    return search(node->left, k);
  else
    return search(node->right, k);
}

template <class T>
RBNode<T>* RBTree<T>::iterativeSearch(RBNode<T>* node, T k) const {
  while (node != nullptr) {
    if (k == node->key)
      break;
    else if (k < node->key)
      node = node->left;
    else
      node = node->right;
  }
  return node;
}

template <class T>
void RBTree<T>::levelOrder() {
  cout << "LevelOrderPrint : " << endl;
  levelOrder(mRoot);
}

template <class T>
void RBTree<T>::levelOrder(RBNode<T>* tree) const {
  if (tree == nullptr) return;
  queue<RBNode<T>*> curLevelNodes;
  curLevelNodes.push(tree);
  int count = 1, nextCount;
  RBNode<T>* node;

  while (!curLevelNodes.empty()) {
    nextCount = 0;
    while (count--) {
      node = curLevelNodes.front();
      curLevelNodes.pop();

      cout << node->key << " ";
      if (node->left != nullptr) {
        nextCount++;
        curLevelNodes.push(node->left);
      }
      if (node->right != nullptr) {
        nextCount++;
        curLevelNodes.push(node->right);
      }
    }
    count = nextCount;
    cout << endl;
  }
}

template <class T>
void RBTree<T>::print() {
  print(mRoot);
}

template <class T>
void RBTree<T>::print(RBNode<T>* tree) {
  int height = getHeight(tree);
}

template <class T>
int RBTree<T>::getHeight() {
  return getHeight(mRoot);
}

template <class T>
int RBTree<T>::getHeight(RBNode<T>* tree) const {
  if (tree == nullptr) return 0;
  return 1 + max(getHeight(tree->left), getHeight(tree->right));
}

template <class T>
void RBTree<T>::preOrder() {
  cout << "PreOrder : " << endl;
  preOrder(mRoot);
  cout << endl << "size : " << size << endl;
}

template <class T>
void RBTree<T>::preOrder(RBNode<T>* tree) const {
  if (tree == nullptr) return;
  cout << tree->key << " ";
  preOrder(tree->left);
  preOrder(tree->right);
}

template <class T>
void RBTree<T>::inOrder() {
  cout << "InOrder : " << endl;
  inOrder(mRoot);
  cout << endl << "size : " << size << endl;
}

template <class T>
void RBTree<T>::inOrder(RBNode<T>* tree) const {
  if (tree == nullptr) return;
  inOrder(tree->left);
  cout << tree->key << " ";
  inOrder(tree->right);
}

template <class T>
void RBTree<T>::postOrder() {
  cout << "PostOrder : " << endl;
  postOrder(mRoot);
  cout << endl << "size : " << size << endl;
}

template <class T>
void RBTree<T>::postOrder(RBNode<T>* tree) const {
  if (tree == nullptr) return;
  postOrder(tree->left);
  postOrder(tree->right);
  cout << tree->key << " ";
}