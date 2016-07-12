/*
245 子树

有两个不同大小的二进制树： T1 有上百万的节点； T2 有好几百的节点。
请设计一种算法，判定 T2 是否为 T1的子树。

 注意事项

若 T1 中存在从节点 n 开始的子树与 T2 相同，我们称 T2 是 T1 的子树。
也就是说，如果在 T1 节点 n 处将树砍断，砍断的部分将与 T2 完全相同。
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
         bool result  = false;
        if (T2 == nullptr) {
            return true;
        }
        if (T1 == nullptr) {
            return false;
        }
        // write your code here
        if (T1->val == T2->val) {
             result = dp(T1,T2);
        }
        if (!result) {
          result =  isSubtree(T1->left,T2);
        }
        if (!result) {
            result =  isSubtree(T1->right,T2);
        }
        return result;
    }
    
    bool dp(TreeNode *T1, TreeNode *T2) {
    
        if (T1 != nullptr && T2!=nullptr && T1->val == T2->val) {
            return dp(T1->left,T2->left) && dp (T1->right,T2->right);
        }
        if (T1 == nullptr && T2 == nullptr) {
            return true;
        }
        return false;
    }
};