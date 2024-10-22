"""
2583. Kth Largest Sum in a Binary Tree
    You are given the root of a binary tree and a positive integer k.
    The level sum in the tree is the sum of the values of the nodes that are on the same level.
    Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
    Note that two nodes are on the same level if they have the same distance from the root.

    Example :
    Input: root = [5,8,9,2,1,3,7,4,6], k = 2
    Output: 13
    Explanation: The level sums are the following:
    - Level 1: 5.
    - Level 2: 8 + 9 = 17.
    - Level 3: 2 + 1 + 3 + 7 = 13.
    - Level 4: 4 + 6 = 10.
    The 2nd largest level sum is 13.
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
from collections import deque
from typing import Optional
import heapq
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        q = deque([root])
        size = []
        while q:
            level = 0
            for i in range(len(q)):
                node = q.popleft()
                level += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            heapq.heappush(size, level)
            if len(size) > k:
                heapq.heappop(size)
        return -1 if len(size) < k else size[0]