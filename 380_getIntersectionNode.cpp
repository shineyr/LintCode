/*
380 两个链表的交叉

请写一个程序，找到两个单链表最开始的交叉节点。

 注意事项

如果两个链表没有交叉，返回null。
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }//if
        
        int lenA = 0, lenB = 0;
        ListNode *p = headA, *q = headB;
        while(p)
        {
            ++lenA;
            p = p->next;
        }//while
        
        while(q)
        {
            ++lenB;
            q = q->next;
        }//while
        
        if(lenA > lenB)
        {
            int i=0;
            p = headA;
            q = headB;
            while(i<lenA-lenB)
            {
                p = p->next;
                ++i;
            }//while
        }else{
            int j = 0;
            q = headB;
            p = headA;
            while(j < lenB - lenA)
            {
                q = q->next;
                ++j;
            }//while
        }//else
        
        while(p && q && p != q)
        {
            p = p->next;
            q = q->next;
        }//while
        
        return p;
    }
};