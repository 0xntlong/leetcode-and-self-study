"""
684. Redundant Connection
    In this problem, a tree is an undirected graph that is connected and has no cycles.
    You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
    Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

    Example :
    Input: edges = [[1,2],[1,3],[2,3]]
    Output: [2,3]
"""

from typing import List
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        root = list(range(len(edges) + 1))

        def find(node):
            if root[node] != node:
                root[node] = find(root[node])
            return root[node]

        for node1, node2 in edges:
            root1, root2 = find(node1), find(node2)

            if root1 == root2:
                return [node1, node2]

            root[root2] = root1