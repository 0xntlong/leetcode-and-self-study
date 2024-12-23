"""
2471. Minimum Number of Operations to Sort a Binary Tree by Level
    You are given the root of a binary tree with unique values.
    In one operation, you can choose any two nodes at the same level and swap their values.
    Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.
    The level of a node is the number of edges along the path between it and the root node.

    Example :
    Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
    Output: 3
    Explanation:
    - Swap 4 and 3. The 2nd level becomes [3,4].
    - Swap 7 and 5. The 3rd level becomes [5,6,8,7].
    - Swap 8 and 7. The 3rd level becomes [5,6,7,8].
    We used 3 operations so return 3.
    It can be proven that 3 is the minimum number of operations needed.
"""

from collections import deque
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        ans = 0
        q = deque([root])
        while q:
            vals = []
            child = list(range(len(q)))
            for _ in range(len(q)):
                node = q.popleft()
                vals.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            
            child.sort(key=lambda i : vals[i])

            for i in range(len(child)):
                while child[i] != i:
                    ans += 1
                    child[child[i]], child[i] = child[i], child[child[i]]

        return ans