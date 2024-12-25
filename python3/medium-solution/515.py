"""
515. Find Largest Value in Each Tree Row
    Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

    Example 1:
    Input: root = [1,3,2,5,3,null,9]
    Output: [1,3,9]
    Example 
    Input: root = [1,2,3]
    Output: [1,3]
"""
from collections import deque
from typing import List, Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        q = deque()
        q.append(root)
        arr = []
        while q:
            max_value = float('-inf')
            for _ in range(len(q)):
                node = q.popleft()
                max_value = max(max_value, node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            arr.append(max_value)
        return arr
