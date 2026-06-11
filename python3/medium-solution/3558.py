"""
3558. Number of Ways to Assign Edge Weights I
    There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
    Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
    The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
    Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.
    Since the answer may be large, return it modulo 109 + 7.
    Note: Ignore all edges not in the path from node 1 to x.


    Example :

    Input: edges = [[1,2]]

    Output: 1

    Explanation:

    The path from Node 1 to Node 2 consists of one edge (1 → 2).
    Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
"""

from typing import List

class Solution:
    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        mod = 10**9 + 7
        n = len(edges) + 1
        graph = [[] for _ in range(n + 1)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        def DFS(node : int, prev : int) -> int:
            dist = 0
            for c in graph[node]:
                if c != prev:
                    dist = max(dist, DFS(c, node) + 1)
            return dist
        
        return pow(2, DFS(1, 0) - 1, mod)