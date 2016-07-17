/*
376  二叉树的路径和
给定一个二叉树，找出所有路径中各节点相加总和等于给定 目标值 的路径。

一个有效的路径，指的是从根节点到叶节点的路径。
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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    void findPath(vector<vector<int>> &ret, vector<int> &path, TreeNode *root, int curSum, int target)
    {
        if(root == NULL)
        {
            return ;
        }
        
        curSum += root->val;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && curSum == target)
        {
            ret.push_back(path);
        }//if
        
        if(root->left != NULL)
        {
            findPath(ret,path,root->left,curSum,target);
        }//if
        
        if(root->right != NULL)
        {
            findPath(ret,path,root->right,curSum,target);
        }
        
        /*返回父节点*/
        path.pop_back();
    }
    
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<vector<int>> ret;
        if(root == NULL)
        {
            return vector<vector<int>>();
        }//if
        vector<int> path;
        findPath(ret,path,root,0,target);
        return ret;
    }
    

};