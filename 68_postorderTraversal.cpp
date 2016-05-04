/*
68 二叉树的后序遍历

给出一棵二叉树，返回其节点值的后序遍历。
样例

给出一棵二叉树 {1,#,2,3},

   1
    \
     2
    /
   3

返回 [3,2,1]

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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        if(root == NULL)
        {
            return vector<int>();
        }//if
        
        stack<TreeNode *> stk1,stk2;
        vector<int> ret;
        
        stk1.push(root);
        while(!stk1.empty())
        {
            TreeNode *tmp = stk1.top();
            stk1.pop();
            
            stk2.push(tmp);
            
            if(tmp->left)
            {
                stk1.push(tmp->left);
            }//if
            
            if(tmp->right)
            {
                stk1.push(tmp->right);
            }//if
        }//while
        
        while(!stk2.empty())
        {
            ret.push_back(stk2.top()->val);
            stk2.pop();
        }//while
        
        return ret;
    }
    
    ///*非递归实现后序遍历2*/
    //void postOrderRecur2(TreeNode *h)
    //{
    //	if (!h)
    //		return;
    //
    //	/*实现过程中，h代表最近一次弹出并打印的节点*/
    //	stack<TreeNode *> stk;
    //	stk.push(h);
    //	TreeNode *tmp;
    //	while (!stk.empty())
    //	{
    //		/*tmp代表栈顶节点*/
    //		tmp = stk.top();
    //		if (tmp->left && h != tmp->left && h != tmp->right)
    //		{
    //			stk.push(tmp->left);
    //		}//else
    //		else if (tmp->right && h != tmp->right)
    //		{
    //			stk.push(tmp->right);
    //		}//elif
    //		else
    //		{
    //			cout << tmp->val << "\t";
    //			stk.pop();
    //			h = tmp;
    //		}//else
    //	}//while
    //}
};