"""
3331. Find Subtree Sizes After Changes
    You are given a tree rooted at node 0 that consists of n nodes numbered from 0 to n - 1. The tree is represented by an array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

    You are also given a string s of length n, where s[i] is the character assigned to node i.

    We make the following changes on the tree one time simultaneously for all nodes x from 1 to n - 1:

    Find the closest node y to node x such that y is an ancestor of x, and s[x] == s[y].
    If node y does not exist, do nothing.
    Otherwise, remove the edge between x and its current parent and make node y the new parent of x by adding an edge between them.
    Return an array answer of size n where answer[i] is the size of the subtree rooted at node i in the final tree.

    Example :
    Input: parent = [-1,0,0,1,1,1], s = "abaabc"
    Output: [6,3,1,1,1,1]
    Explanation:
    The parent of node 3 will change from node 1 to node 0.
"""


from typing import List
from collections import defaultdict


class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        graph = defaultdict(list)
        for i in range(1, len(parent)):
            graph[parent[i]].append(i)

        n = len(parent)
        ans = [1] * n

        def dfs(node, letters):
            c = s[node]
            letters[c].append(node)

            for child in graph[node]:
                x = dfs(child, letters)
                ans[node] += x

            letters[c].pop()

            if letters[c]:
                ans[letters[c][-1]] += ans[node]
                return 0
            else:
                return ans[node]

        dfs(0, defaultdict(list))
        return ans