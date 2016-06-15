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
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode1(TreeNode* root, TreeNode* node) {
        // write your code here
        if(root == NULL)
        {
            root = node;
            return root;
        }//if
        
        if(node->val < root->val)
        {
            if(root->left == NULL)
            {
                root->left = node;
            }else{
                root->left = insertNode1(root->left, node);
            }//else
        }else{
            if(root->right == NULL)
            {
                root->right = node;
            }else{
                root->right = insertNode1(root->right, node);
            }//else
        }//else
        
        return root;
    }
    
    //非递归
     TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if(root == NULL)
        {
            root = node;
            return root;
        }//if
        
        TreeNode *t = root;
        while(t != NULL)
        {
            if(node->val < t->val)
            {
                
                if(t->left == NULL)
                {
                    t->left = node;
                    return root;
                }else{
                    t = t->left;;
                    continue;
                }//else
            }//if
            else{
                if(t->right == NULL)
                {
                    t->right = node;
                    return root;
                }else{
                    t = t->right;
                    continue;
                }//else
            }//else
        }//while
        return root;
     }
};