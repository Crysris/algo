#include "../etc/utils.h"


/*=======================================================================================
     leetcode142. Linked List Cycle II
*/
ListNode *detectCycle(ListNode *head) {
    ListNode *p=head;
    ListNode *q=head;
    while(p!=nullptr&&q!=nullptr){
        if(p==q)break;
        if(q->next==nullptr)return nullptr;
        p=p->next;
        q=q->next->next;
    }
    return p;
}
void code142(){

}