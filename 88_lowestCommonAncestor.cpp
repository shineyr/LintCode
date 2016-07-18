/*
88 最近公共祖先

给定一棵二叉树，找到两个节点的最近公共父节点(LCA)。

最近公共祖先是两个节点的公共的祖先节点且具有最大深度。
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
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if(root == NULL || A == NULL || B == NULL)
        {
            return NULL;
        }//if
        
        vector<TreeNode *> lA,lB,cur;
        dfs(cur,root,A,B,lA,lB);
        
        return getLastCommonNode(lA,lB);
    }
    
    void dfs(vector<TreeNode*> cur,TreeNode*root,TreeNode *A, TreeNode *B,vector<TreeNode*> &APath,vector<TreeNode*> &BPath)  
    {  
        cur.push_back(root);  
        if(root==A)  
            APath = cur;  
        if(root==B)  
            BPath = cur;  
        if(root->left)  
            dfs(cur,root->left,A,B,APath,BPath);  
        if(root->right)  
            dfs(cur,root->right,A,B,APath,BPath);  
    }  
        
    TreeNode *getLastCommonNode(vector<TreeNode *> lA, vector<TreeNode *> lB)
    {
        if(lA.empty() || lB.empty())
        {
            return NULL;
        }//if
        
        TreeNode *ret = NULL;
        vector<TreeNode *>::iterator iter1 = lA.begin();
        vector<TreeNode *>::iterator iter2 = lB.begin();
        while(iter1 != lA.end() && iter2 != lB.end())
        {
            if(*iter1 == *iter2)
            {
                ret = *iter1;
            }
            ++iter1;
            ++iter2;
        }//while
        return ret;
    }
};