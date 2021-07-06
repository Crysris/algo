#include "../etc/utils.h"
/*=======================================================================================
    leetcode 2. Add Two Numbers
    逆序数字链表
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int res = 0, numberPos = 1;
  while (l1 != nullptr) {
    res = res + (l1->val + l2->val) * numberPos;
    l1 = l1->next;
    l2 = l2->next;
    numberPos *= 10;
  }
  ListNode *ans = nullptr, *pre = nullptr, *p;
  int lastNumber;
  while (res > 0) {
    lastNumber = res - 10 * (res / 10);
    res = res / 10;
    if (pre == nullptr) {
      ans = new ListNode(lastNumber);
      pre = ans;
      p = ans;
      continue;
    }
    p = new ListNode(lastNumber);
    pre->next = p;
    pre = p;
  }
  return ans;
}
void code2() {
  ListNode* node[LIST_NODE_NUMBER];
  node[0] = new ListNode(9);
  node[1] = new ListNode(8);
  node[2] = new ListNode(7);
  node[3] = new ListNode(2);
  node[4] = new ListNode(6);
  //(8)->(7)->(2)->(6)
  node[5] = new ListNode(3);
  node[6] = new ListNode(4);
  node[7] = new ListNode(9);
  node[8] = new ListNode(7);
  node[9] = new ListNode(5);
  //(3)->(4)->(9)->(7)
  int i = 0, j = 5;
  while (i < 4) {
    node[i]->next = node[i + 1];
    node[j]->next = node[j + 1];
    i++;
    j++;
  }
  addTwoNumbers(node[0], node[5]);
}
//=======================================================================================
int main() {
  code2();
  return 0;
}