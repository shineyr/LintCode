/*
104 合并k个排序链表

合并k个排序链表，并且返回合并后的排序链表。尝试分析和描述其复杂度。
样例
给出3个排序链表[2->4->null,null,-1->null]，返回 -1->2->4->null
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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if(lists.empty())
        {
            return NULL;
        }//if
        
        int n = lists.size();
        ListNode *head = lists[0];
        for(int i=1; i<n; ++i)
        {
            head = merge(head,lists[i]);
        }//for
        
        return head;
        
    }
    
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        if(head1 == NULL)
        {
            return head2;
        }//if
        
        if(head2 == NULL)
        {
            return head1;
        }//if
        
        ListNode *p = head1 , *q = head2;
        ListNode *head = NULL, *r = head;
        
        while(p != NULL && q != NULL)
        {
            if(p->val <= q->val)
            {
                if(head == NULL)
                {
                    head = p;
                    r = head;
                }else {
                    r->next = p;
                    r = r->next;
                }//else
                p = p->next;
                r->next = NULL;
            }else{
                if(head == NULL)
                {
                    head = q;
                    r = head;
                }else{
                    r->next = q;
                    r = r->next;
                }//else
                q = q->next;
                r->next = NULL;
            }//else
        }//while
        
        if(p)
        {
            r->next = p;
        }//if
        
        if(q)
        {
            r->next = q;
        }//if
        
        return head;
    }
};


