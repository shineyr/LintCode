/*

69 二叉树的层次遍历

给出一棵二叉树，返回其节点值的层次遍历（逐层从左往右访问）


给一棵二叉树 {3,9,20,#,#,15,7} ：

  3
 / \
9  20
  /  \
 15   7

返回他的分层遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

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
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        if(root == NULL)
        {
            return vector<vector<int>>();
        }//if
        
        queue<TreeNode *> parent;
        parent.push(root);
        
        vector<vector<int>> ret;
        
        while(!parent.empty())
        {
            vector<int> v;
            queue<TreeNode *> childs;
            
            while(!parent.empty())
            {
                TreeNode *tmp = parent.front();
                parent.pop();
                v.push_back(tmp->val);
                
                if(tmp->left != NULL)
                {
                    childs.push(tmp->left);
                }//if
                
                if(tmp->right != NULL)
                {
                    childs.push(tmp->right);
                }//if
            }//while
            ret.push_back(v);
            parent = childs;
        }//while
        
        return ret;
    }
};
