"""
889. Construct Binary Tree from Preorder and Postorder Traversal
    Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
    If there exist multiple answers, you can return any of them.

    Example :
    Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
    Output: [1,2,3,4,5,6,7]
"""

from typing import List, Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:

    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not postorder:
            return None

        val = postorder.pop()
        node = TreeNode(val)

        if not postorder:
            return node

        idx = postorder.index(preorder[1])
        node.left = self.constructFromPrePost(preorder[1:idx + 2], postorder[:idx + 1])
        node.right = self.constructFromPrePost(preorder[idx + 2:], postorder[idx + 1:])

        return node
        