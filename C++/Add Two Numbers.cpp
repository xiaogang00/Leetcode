#include <iostream>
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {  
public:  
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {  
        // IMPORTANT: Please reset any member data you declared, as  
        // the same Solution instance will be reused for each test case.  
          
        if (l1 == NULL) return l2;  
        if (l2 == NULL) return l1;  
  
        ListNode *resList = NULL, *pNode = NULL, *pNext = NULL;  
        ListNode *p = l1, *q = l2;  
        int up = 0;  
        while(p != NULL && q != NULL)  
        {  
            pNext = new ListNode(p->val + q->val + up);  
            up = pNext->val / 10;    //计算进位  
            pNext->val = pNext->val % 10;   //计算该位的数字  
              
            if (resList == NULL)  //头结点为空  
            {  
                resList = pNode = pNext;  
            }  
            else //头结点不为空  
            {  
                pNode->next = pNext;  
                pNode = pNext;  
            }  
            p = p->next;  
            q = q->next;  
        }  
  
        //处理链表l1剩余的高位  
        while (p != NULL)  
        {  
            pNext = new ListNode(p->val + up);  
            up = pNext->val / 10;      
            pNext->val = pNext->val % 10;  
            pNode->next = pNext;  
            pNode = pNext;  
            p = p->next;  
        }  
  
        //处理链表l2剩余的高位  
        while (q != NULL)  
        {  
            pNext = new ListNode(q->val + up);  
            up = pNext->val / 10;      
            pNext->val = pNext->val % 10;  
            pNode->next = pNext;  
            pNode = pNext;  
            q = q->next;  
        }  
  
        //如果有最高处的进位，需要增加结点存储  
        if (up > 0)  
        {  
            pNext = new ListNode(up);  
            pNode->next = pNext;  
        }  
  
        return resList;  
    }  
  
};  