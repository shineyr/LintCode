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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        return buildSubTree(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }
    
    TreeNode *buildSubTree(vector<int>::iterator inBeg, vector<int>::iterator inEnd,
        vector<int>::iterator postBeg, vector<int>::iterator postEnd)
    {
        if(inBeg == inEnd || postBeg == postEnd)
        {
            return NULL;
        }//if
        
        TreeNode *root = new TreeNode(*(postEnd - 1));
        
        vector<int>::iterator pos = find(inBeg, inEnd, root->val);
        
        if(pos != inEnd)
        {
            int leftLen = pos - inBeg - 1;
            root->left = buildSubTree(inBeg,inBeg+leftLen+1, postBeg,postBeg+leftLen+1);
            root->right = buildSubTree(inBeg+leftLen+2,inEnd, postBeg+leftLen+1, postEnd -1 );
        }//if
        
        return root;
    }
};