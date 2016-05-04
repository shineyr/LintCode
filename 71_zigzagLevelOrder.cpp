/*
71 二叉树的锯齿形层次遍历

给出一棵二叉树，返回其节点值的锯齿形层次遍历
（先从左往右，下一层再从右往左，层与层之间交替进行） 

给出一棵二叉树 {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

返回其锯齿形的层次遍历为：

[
  [3],
  [20,9],
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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
         if(root == NULL)
        {
            return vector<vector<int>>();
        }//if
        
        queue<TreeNode *> parent;
        parent.push(root);
        
        vector<vector<int>> ret;
        
        bool flag = true;
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
            if(flag)
            {
                ret.push_back(v);
                flag = !flag;
            }//if
            else{
                reverse(v.begin(),v.end());
                ret.push_back(v);
                flag = !flag;
            }
            parent = childs;
        }//while
        return ret;
    }
};