"""
1382. Balance a Binary Search Tree
    Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
    A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

    Example :
    Input: root = [1,null,2,null,3,null,4,null,null]
    Output: [2,1,3,null,null,null,4]
    Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
"""
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return 
        Nodes = []
        def inorder(node):
            if node is None:
                return
            inorder(node.left)
            Nodes.append(node)
            inorder(node.right)
        inorder(root)

        def balance(left, right):
            if left > right:
                return None
            mid = (left + right) // 2
            root = Nodes[mid]
            root.left = balance(left, mid - 1)
            root.right = balance(mid + 1, right)
            return root
        return balance(0, len(Nodes) - 1)