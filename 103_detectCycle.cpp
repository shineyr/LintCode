/**
103 带环链表 II

给定一个链表，如果链表中存在环，则返回到链表中环的起始节点的值，如果没有环，返回null。

您在真实的面试中是否遇到过这个题？ Yes
样例
给出 -21->10->4->5, tail connects to node index 1，返回10

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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if(head == NULL || head->next ==NULL)
        {
            return NULL;
        }//if
        
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                break;
            }//if
        }//while
        
        if(fast && fast == slow)
        {
            fast = head;
            while(fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }//while
            
            return fast;
        }//if
        return NULL;
        
    }
};


