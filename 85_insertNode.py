"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


class Solution:
    """
    @param root: The root of the binary search tree.
    @param node: insert this node into the binary search tree.
    @return: The root of the new binary search tree.
    """

    def insertNode1(self, root, node):
        # write your code here
        if root is None:
            root = node
            return root

        if node.val < root.val:
            root.left = self.insertNode1(root.left, node)
        else:
            root.right = self.insertNode1(root.left, node)

        return root

    #非递归
    def insertNode(self, root, node):
        # write your code here
        if root is None:
            root = node
            return root

        t = root
        while t is not None:
            if node.val < t.val:
                if t.left is None:
                    t.left = node
                    return root
                else:
                    t = t.left
                    continue
            else:
                if t.right is None:
                    t.right = node
                    return root
                else:
                    t = t.right
                    continue
        return root
