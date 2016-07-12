/*
372 在O(1)时间复杂度删除链表节点

给定一个单链表中的一个等待被删除的节点(非表头或表尾)。请在在O(1)时间复杂度删除该链表节点。

样例
给定 1->2->3->4，和节点 3，删除 3 之后，链表应该变为 1->2->4。
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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        if(node == NULL)
        {
            return ;
        }//if
        else if(node->next == NULL)
        {
            ListNode *p = node;
            node = NULL;
            
            delete p;
            p = NULL;
        }else{
            node->val = node->next->val;
            ListNode *p = node->next;
            node->next = p->next;
            
            delete p;
            p = NULL;
        }
    }
};