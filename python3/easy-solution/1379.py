"""
1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
    Given two binary trees original and cloned and given a reference to a node target in the original tree.
    The cloned tree is a copy of the original tree.
    Return a reference to the same node in the cloned tree.
    Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

    Example:
    Input: tree = [7,4,3,null,null,6,19], target = 3
    Output: 3
    Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.
"""
from typing import List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        if not cloned:
            return None
        if cloned.val == target.val:
            return cloned
        left_result = self.getTargetCopy(original, cloned.left, target)
        if left_result:
            return left_result
        return self.getTargetCopy(original, cloned.right, target)