"""
2458. Height of Binary Tree After Subtree Removal Queries
    You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.
    You have to perform m independent queries on the tree where in the ith query you do the following:
    Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
    Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.
    Note:
    The queries are independent, so the tree returns to its initial state after each query.
    The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.

    Example:
    Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
    Output: [2]
    Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
    The height of the tree is 2 (The path 1 -> 3 -> 2).
"""

from functools import cache
from typing import List, Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# APPROACH 1:
class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        height = {}
        def DFS(node, depth):
            if not node:
                return depth
            height[node.val] = max(DFS(node.left, depth + 1), DFS(node.right, depth + 1))
            return height[node.val]
        res = {}
        def DFS2(node, depth, max_external_heigh):
            if not node:
                return 
            children = list(filter(None, [node.left, node.right]))
            res[node.val] = max(max_external_heigh, depth)
            if not children:
                return 
            if len(children) == 1:
                DFS2(children[0], depth + 1, max_external_heigh)
                return
            DFS2(children[0], depth + 1, max(max_external_heigh, height[children[1].val]))
            DFS2(children[1], depth + 1, max(max_external_heigh, height[children[0].val]))
        DFS(root, -1)
        DFS2(root, -1, 0)
        return list(map(res.__getitem__, queries))



# APPROACH 2:
class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        @cache
        def DFS(node):
            if node is None:
                return 0
            return max(DFS(node.left),DFS(node.right)) + 1
        lookup = {}
        def calculate_depth(node, depth, max_other):
            if node is None:
                return 
            left_height = DFS(node.left)
            right_height = DFS(node.right)
            if node.left is not None:
                lookup[node.left.val] = max(right_height + depth, max_other)
                calculate_depth(node.left, depth + 1 , lookup[node.left.val])
            if node.right is not None:
                lookup[node.right.val] = max(left_height + depth, max_other)
                calculate_depth(node.right, depth + 1, lookup[node.right.val])
        calculate_depth(root, 0 ,0)
        result = []
        for q in queries:
            result.append(lookup[q])
        return result