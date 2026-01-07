"""
1339. Maximum Product of Splitted Binary Tree
    Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
    Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
    Note that you need to maximize the answer before taking the mod and not after taking it.

    Example :
    Input: root = [1,2,3,4,5,6]
    Output: 110
    Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
"""

from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        mod = 10 ** 9 + 7
        sub = []
        def dfs(node):
            if not node:
                return 0
            s = node.val + dfs(node.left) + dfs(node.right)
            sub.append(s)
            return s
        total = dfs(root)
        best = 0
        for i in sub:
            best = max(best, i * (total - i))
        return best % mod