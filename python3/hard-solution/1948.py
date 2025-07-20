"""
1948. Delete Duplicate Folders in System
    Due to a bug, there are many duplicate folders in a file system. You are given a 2D array paths, where paths[i] is an array representing an absolute path to the ith folder in the file system.
    For example, ["one", "two", "three"] represents the path "/one/two/three".
    Two folders (not necessarily on the same level) are identical if they contain the same non-empty set of identical subfolders and underlying subfolder structure. The folders do not need to be at the root level to be identical. If two or more folders are identical, then mark the folders as well as all their subfolders.
    For example, folders "/a" and "/b" in the file structure below are identical. They (as well as their subfolders) should all be marked:
    /a
    /a/x
    /a/x/y
    /a/z
    /b
    /b/x
    /b/x/y
    /b/z
    However, if the file structure also included the path "/b/w", then the folders "/a" and "/b" would not be identical. Note that "/a/x" and "/b/x" would still be considered identical even with the added folder.
    Once all the identical folders and their subfolders have been marked, the file system will delete all of them. The file system only runs the deletion once, so any folders that become identical after the initial deletion are not deleted.
    Return the 2D array ans containing the paths of the remaining folders after deleting all the marked folders. The paths may be returned in any order.

    Example 1:

    Input: paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
    Output: [["d"],["d","a"]]
    Explanation: The file structure is as shown.
    Folders "/a" and "/c" (and their subfolders) are marked for deletion because they both contain an empty
    folder named "b".
"""

from typing import List
from collections import defaultdict


class Node:
    def __init__(self, name):
        self.name = name
        self.children = {}
        self.signature = ""

class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        root = Node("")

        for path in paths:
            node = root
            for folder in path:
                if folder not in node.children:
                    node.children[folder] = Node(folder)
                node = node.children[folder]
        count = defaultdict(int)
        def DFS(node):
            if not node.children:
                node.signature = ""
                return ""
            child_signs = []
            for name, child in sorted(node.children.items()):
                sig = DFS(child)
                child_signs.append(f"{name}({sig})")

            node.signature = "".join(child_signs)
            count[node.signature] += 1
            return node.signature
        DFS(root)
        res = []
        curr_path = []

        def DFS2(node):
            if node.signature and count[node.signature] > 1:
                return
            if node.name:
                curr_path.append(node.name)
                res.append(curr_path.copy())
            for name, child in sorted(node.children.items()):
                DFS2(child)
            if node.name:
                curr_path.pop()
        for name, child in sorted(root.children.items()):
            DFS2(child)
        return res