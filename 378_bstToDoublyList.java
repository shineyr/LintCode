/**
378 将二叉查找树转换成双链表

将一个二叉查找树按照中序遍历转换成双向链表。
*/

/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 * Definition for Doubly-ListNode.
 * public class DoublyListNode {
 *     int val;
 *     DoublyListNode next, prev;
 *     DoublyListNode(int val) {
 *         this.val = val;
 *         this.next = this.prev = null;
 *     }
 * }
 */ 
public class Solution {
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */

    public DoublyListNode bstToDoublyList(TreeNode root) {
        if(null == root) return null;
        DoublyListNode result = bstToDoublyList2(root);
        while(result.prev != null)
            result = result.prev;
        return result;
    }

    public DoublyListNode bstToDoublyList2(TreeNode root) {
        if(null == root) return null;
        DoublyListNode node = new DoublyListNode(root.val);
        if(null != root.left) {
            DoublyListNode left = bstToDoublyList2(root.left);
            while(left.next != null)
                left = left.next;
            node.prev = left;
            left.next = node;
        }
        if(null != root.right) {
            DoublyListNode right = bstToDoublyList2(root.right);
            while(right.prev != null)
                right = right.prev;
            node.next = right;
            right.prev = node;
        }
        return node;
    }
}