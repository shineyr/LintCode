/*
99 重排链表

给定一个单链表L： L0→L1→…→Ln-1→Ln,

重新排列后为：L0→Ln→L1→Ln-1→L2→Ln-2→…

必须在不改变节点值的情况下进行原地操作

样例
给出链表1->2->3->4->null，重新排列后为1->4->2->3->null。
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL)
        {
            return ;
        }//if
        
        ListNode *p = head, *q = head->next;
        while(q && q->next)
        {
            p = p->next;
            q = q->next->next;
        }//while
        
        q = p->next;
        p->next = NULL;
        //后半段节点先逆序再逐个插入
        ListNode *rHead = NULL;
        while(q)
        {
            ListNode *r = q->next;
            q->next = rHead;
            rHead = q;
            q = r;
        }//while
        
        q = rHead;
        p = head;
        while(p&&q)
        {
            ListNode *rr = q->next;
            ListNode *lr = p->next;
            q->next = lr;
            p->next = q;
            
            q = rr;
            p = lr;
        }//while
        
    }
};


