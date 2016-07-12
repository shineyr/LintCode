/*
165 合并两个排序链表

将两个排序链表合并为一个新的排序链表

样例
给出 1->3->8->11->15->null，2->null， 返回 1->2->3->8->11->15->null。
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if(l1 == NULL)
        {
            return l2;
        }
        
        if(l2 == NULL)
        {
            return l1;
        }
        
        ListNode *head = NULL, *p = NULL, *q = NULL;;
        if(l1->val < l2->val)
        {
            head = l1;
            p = l1->next;
            q = l2;
        }else{
            head = l2;
            q = l2->next;
            p = l1;
        }
        
        ListNode *r = head;
        while(p && q)
        {
            if(p->val < q->val)
            {
                r->next = p;
                p = p->next;
            }else{
                r->next = q;
                q = q->next;
            }
            r = r->next;
        }//while
        
        while(p)
        {
            r->next = p;
            p = p->next;
            r = r->next;
        }
        
        while(q)
        {
            r->next = q;
            q = q->next;
            r = r->next;
        }
        
        r->next = NULL;
        return head;
    }
};