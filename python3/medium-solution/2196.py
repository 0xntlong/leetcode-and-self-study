"""
2196. Create Binary Tree From Descriptions
    You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,
    If isLefti == 1, then childi is the left child of parenti.
    If isLefti == 0, then childi is the right child of parenti.
    Construct the binary tree described by descriptions and return its root.
    The test cases will be generated such that the binary tree is valid.

    Example :
    Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
    Output: [50,20,80,15,17,19]
    Explanation: The root node is the node with value 50 since it has no parent.
    The resulting binary tree is shown in the diagram.
"""


from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        nodes, children = {}, set()
        for val, child, is_left in descriptions:
            node = None
            if val in nodes:
                node = nodes[val]
            else:
                node = TreeNode(val)
                nodes[val] = node
            child_node = None
            if child in nodes:
                child_node = nodes[child]
            else:
                child_node = TreeNode(child)
                nodes[child] = child_node
            children.add(child)
            if is_left == 1:
                node.left = child_node
            else:
                node.right = child_node
        for node in nodes.keys():
            if node not in children:
                return nodes[node]
        return None