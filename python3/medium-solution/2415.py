"""
2415. Reverse Odd Levels of Binary Tree
    Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.
    For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
    Return the root of the reversed tree.
    A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.
    The level of a node is the number of edges along the path between it and the root node.

    Example :
    Input: root = [2,3,5,8,13,21,34]
    Output: [2,5,3,8,13,21,34]
    Explanation: 
    The tree has only one odd level.
    The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.
"""

from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def DFS(child_left, child_right, level):
            if not child_left or not child_right:
                return 0
            if level % 2 == 0:
                child_left.val, child_right.val = child_right.val, child_left.val
            DFS(child_left.left, child_right.right, level + 1)
            DFS(child_left.right, child_right.left, level + 1)
        DFS(root.left, root.right, 0)
        return root