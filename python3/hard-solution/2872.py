"""
2872. Maximum Number of K-Divisible Components
    There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
    You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.
    A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by k, where the value of a connected component is the sum of the values of its nodes.
    Return the maximum number of components in any valid split.

    Example :
    Input: n = 5, edges = [[0,2],[1,2],[1,3],[2,4]], values = [1,8,1,4,4], k = 6
    Output: 2
    Explanation: We remove the edge connecting node 1 with 2. The resulting split is valid because:
    - The value of the component containing nodes 1 and 3 is values[1] + values[3] = 12.
    - The value of the component containing nodes 0, 2, and 4 is values[0] + values[2] + values[4] = 6.
    It can be shown that no other valid split has more than 2 connected components.
"""

from typing import List
from collections import defaultdict

class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adj = defaultdict(list)

        for node1, node2 in edges:
            adj[node1].append(node2)
            adj[node2].append(node1)

        res = 0
        def DFS(cur, parent):
            total = values[cur]
            for child in adj[cur]:
                if child != parent:
                    total += DFS(child, cur)
            if total % k == 0:
                nonlocal res
                res += 1
            return total
        DFS(0, -1)
        return res