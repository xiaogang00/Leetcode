//
// Created by Theo on 2017/7/23.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL) return head;
        ListNode* p = head;
        int len = 1;
        //(1) 计算链表长度
        while(p->next != NULL)
        {
            p = p->next;
            len++;
        }

        //(2) 让链表头尾相连
        p->next = head;
        //(3) 找到结果链表的尾节点
        k %= len;
        int step = len - k;
        while(step > 0)
        {
            p = p->next;
            step--;
        }

        //(4) 断开链表，从结果链表的尾节点位置 新的头结点，是结果链表尾节点的下一个结点。结果链表尾节点->next 置NULL
        head = p->next;
        p->next = NULL;

        return head;
    }
};