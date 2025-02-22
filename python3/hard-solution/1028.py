"""
1028. Recover a Tree From Preorder Traversal
    We run a preorder depth-first search (DFS) on the root of a binary tree.
    At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
    If a node has only one child, that child is guaranteed to be the left child.
    Given the output traversal of this traversal, recover the tree and return its root.

    Example :
    Input: traversal = "1-2--3--4-5--6--7"
    Output: [1,2,5,3,4,6,7]
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from typing import Optional

class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        stack, i = [], 0
        while i < len(traversal):
            depth, value = 0, 0
            
            while i < len(traversal) and traversal[i] == '-':
                depth += 1
                i += 1
            
            while i < len(traversal) and traversal[i].isdigit():
                value = value * 10 + int(traversal[i])
                i += 1
            
            node = TreeNode(value)
        
            while len(stack) > depth:
                stack.pop()

            if stack:
                if not stack[-1].left:
                    stack[-1].left = node
                else:
                    stack[-1].right = node
            stack.append(node)
            
        return stack[0]  