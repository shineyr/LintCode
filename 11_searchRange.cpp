/*
11  二叉查找树中搜索区间

给定两个值 k1 和 k2（k1 < k2）和一个二叉查找树的根节点。找到树中所有值在 k1 到 k2 范围内的节点。
即打印所有x (k1 <= x <= k2) 其中 x 是二叉查找树的中的节点值。返回所有升序的节点值。

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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> inOrderData;
        inOrder(root, inOrderData);
        
        vector<int> ret;
        for(auto iter = inOrderData.begin() ; iter!=inOrderData.end() ; ++iter)
        {
            if((*iter) >= k1 && (*iter) <= k2)
            {
                ret.push_back(*iter);
            }//if
        }//for
        
        return ret;
        
    }
    
    void inOrder(TreeNode *root, vector<int> &ret)
    {
        if(root == NULL)
        {
            return ;
        }//if
        
        if(root->left != NULL)
        {
            inOrder(root->left , ret);
        }//if
        
        ret.push_back(root->val);
        
        if(root->right != NULL)
        {
            inOrder(root->right , ret);
        }
        
        return ;
    }
};