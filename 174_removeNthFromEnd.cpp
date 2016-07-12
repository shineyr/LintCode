/*
174 删除链表中倒数第n个节点

给定一个链表，删除链表中倒数第n个节点，返回链表的头节点。


链表中的节点个数大于等于n

样例
给出链表1->2->3->4->5->null和 n = 2.

删除倒数第二个节点之后，这个链表将变成1->2->3->5->null.
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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        if(head == NULL || n <= 0)
        {
            return head;
        }
        
        ListNode *p = head;
        int k = 1;
        while(p->next && k < n)
        {
            p = p->next;
            ++k;
        }//while
        
        if(k < n)
        {
            return head;
        }//if
        
        ListNode *q = head,*pre = q;
        while(p->next)
        {
            pre = q;   
            q = q->next;
            p = p->next;
        }//while
        
        if(q == head)
        {
            head = head->next;
            delete q;
        }else{
            pre->next = q->next;
            delete q;
            q = NULL;
        }
        
        return head;
    }
};


