"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class TreeNode:
    def __init__(self,val):
        self.val = val
        self.left,self.right = None, None


def buildSubTree(inorder, inBeg, inEnd, postorder, postBeg, postEnd):
    inLen = len(inorder)
    postLen = len(postorder)
    if inBeg == inEnd or inEnd > inLen or postBeg == postEnd or postEnd > postLen:
        return None

    root = TreeNode(postorder[postEnd - 1])
    pos = inorder.index(root.val)

    leftLen = pos - inBeg - 1
    root.left = buildSubTree(inorder, inBeg, inBeg + leftLen + 1, postorder, postBeg, postBeg + leftLen + 1)
    root.right = buildSubTree(inorder, inBeg + leftLen + 2, inEnd, postorder, postBeg + leftLen + 1, postEnd - 1)

    return root


class Solution:
    """
    @param inorder : A list of integers that inorder traversal of a tree
    @param postorder : A list of integers that postorder traversal of a tree
    @return : Root of a tree
    """

    def buildTree(self, inorder, postorder):
        # write your code here
        return buildSubTree(inorder, 0, len(inorder), postorder, 0, len(postorder))


s = Solution()

inorder = [1,2]
postorder = [2,1]

root = s.buildTree(inorder,postorder)

