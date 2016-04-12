/*
 35 翻转链表

翻转一个链表

样例
给出一个链表1->2->3->null，这个翻转后的链表为3->2->1->null

挑战
在原地一次翻转完成
*/

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL)
        {
            return head;
        }//if
        
        /*采用头插法反转链表*/
        ListNode *newHead = head;
        ListNode *p = head->next;
        newHead->next = NULL;
        while(p)
        {
            ListNode *r = p->next;
            p->next = newHead;
            newHead = p;
            
            p = r;
        }//while
        return newHead;
    }
};
