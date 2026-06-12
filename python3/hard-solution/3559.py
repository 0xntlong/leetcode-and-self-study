"""
3559. Number of Ways to Assign Edge Weights II
    There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
    Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
    The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
    You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways to assign weights to edges in the path such that the cost of the path between ui and vi is odd.
    Return an array answer, where answer[i] is the number of valid assignments for queries[i].
    Since the answer may be large, apply modulo 109 + 7 to each answer[i].
    Note: For each query, disregard all edges not in the path between node ui and vi.

    Example :

    Input: edges = [[1,2]], queries = [[1,1],[1,2]]
    Output: [0,1]
    Explanation:
    Query [1,1]: The path from Node 1 to itself consists of no edges, so the cost is 0. Thus, the number of valid assignments is 0.
    Query [1,2]: The path from Node 1 to Node 2 consists of one edge (1 → 2). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
"""

from typing import List
from collections import deque

class Solution:
    def assignEdgeWeights(self, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(edges) + 1

        adj = [[] for _ in range(n + 1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        depth = [0] * (n + 1)
        parent = [0] * (n + 1)
        visited = [0] * (n + 1)
        visited[1] = 1
        q = deque([1])
        while q:
            node = q.popleft()
            for nei in adj[node]:
                if not visited[nei]:
                    visited[nei] = 1
                    depth[nei] = depth[node] + 1
                    parent[nei] = node
                    q.append(nei)

        LOG = max(1, n.bit_length())
        up = [parent]
        for k in range(1, LOG):
            prev = up[-1]
            up.append([prev[prev[v]] for v in range(n + 1)])

        def lca(u, v):
            if depth[u] < depth[v]:
                u, v = v, u
            diff = depth[u] - depth[v]
            for k in range(LOG):
                if (diff >> k) & 1:
                    u = up[k][u]
            if u == v:
                return u
            for k in range(LOG - 1, -1, -1):
                if up[k][u] != up[k][v]:
                    u = up[k][u]
                    v = up[k][v]
            return up[0][u]

        pow2 = [1] * (n + 1)
        for i in range(1, n + 1):
            pow2[i] = pow2[i - 1] * 2 % MOD

        ans = []
        for u, v in queries:
            k = depth[u] + depth[v] - 2 * depth[lca(u, v)]
            ans.append(pow2[k - 1] if k else 0)
        return ans