//
// Created by Theo on 2017/7/13.
//

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode tmpNode = ListNode(INT_MIN);

        if (head == NULL || head->next==NULL){
            return head;
        }
        while(head){
            ListNode * pNode = head;
            head = head->next;
            ListNode *pPrev  = &tmpNode;
            ListNode *pNext = pPrev->next;
            while (pNext && pNext->val < pNode->val)
            {
                pPrev = pNext;
                pNext = pNext->next;
            }
            pPrev->next = pNode;
            pNode->next = pNext;
        }
        return tmpNode.next;
    }
};