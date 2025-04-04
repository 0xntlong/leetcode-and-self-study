"""
1123. Lowest Common Ancestor of Deepest Leaves
    Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
    Recall that:
    The node of a binary tree is a leaf if and only if it has no children
    The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
    The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

    Example :
    Input: root = [3,5,1,6,2,0,8,null,null,7,4]
    Output: [2,7,4]
    Explanation: We return the node with value 2, colored in yellow in the diagram.
    The nodes coloured in blue are the deepest leaf-nodes of the tree.
    Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
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
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        q = deque([(root, None)])
        par = {}
        val = {}
        left, right = -1, -1
        d = 0
        while q:
            n = len(q)
            for i in range(n):
                node, parent = q.popleft()
                x = node.val
                y = parent.val if parent else -1

                par[x] = y
                val[x] = node

                if i == 0:
                    left = x
                if i == n - 1:
                    right = x

                if node.left:
                    q.append((node.left, node))
                if node.right:
                    q.append((node.right, node))
            d += 1
        if left == right:
            return val[left]
            
        s, t = left, right
        while s != t:
            s = par[s]
            t = par[t]
        return val[s]
                