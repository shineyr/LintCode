/*
105 复制带随机指针的链表
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if(head == NULL)
        {
            return NULL;
        }//if
        
        RandomListNode *p = head;
        while(p != NULL)
        {
            RandomListNode *r = p->next;
            RandomListNode *tmp = new RandomListNode(p->label);
            tmp->next = p->next;
            p->next = tmp;
            
            p = r;
        }//while
        
        p = head;
        RandomListNode *q = head->next;
        while(p && q)
        {
            if(p->random)
            {
                q->random = p->random->next;
            }
            p = q->next;
            if(p)
            {
                q = p->next;
            }
            
        }//while
        
        RandomListNode *ret = head->next;
        delete head;
        q = ret;
        while(q->next)
        {
            p = q->next;
            q->next = p->next;
            
            delete p;
            
            q = q->next;
        }//while
        
        return ret;
    }
};