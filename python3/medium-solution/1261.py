"""
1261. Find Elements in a Contaminated Binary Tree
    Given a binary tree with the following rules:
    root.val == 0
    For any treeNode:
    If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
    If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
    Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.
    Implement the FindElements class:
    FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
    bool find(int target) Returns true if the target value exists in the recovered binary tree.
    
    Example :
    Input
    ["FindElements","find","find"]
    [[[-1,null,-1]],[1],[2]]
    Output
    [null,false,true]
    Explanation
    FindElements findElements = new FindElements([-1,null,-1]); 
    findElements.find(1); // return False 
    findElements.find(2); // return True 
"""

from collections import deque
from typing import Optional
#Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.hashSet = set()
        if root:
            self.bfs(root)
    
    def bfs(self, root: TreeNode):
        queue = deque([root])
        root.val = 0

        while queue:
            node = queue.popleft()
            x = node.val
            self.hashSet.add(x)

            if node.left:
                node.left.val = 2 * x + 1
                queue.append(node.left)
            if node.right:
                node.right.val = 2 * x + 2
                queue.append(node.right)

    def find(self, target: int) -> bool:
        return target in self.hashSet


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)