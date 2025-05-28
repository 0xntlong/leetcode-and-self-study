"""
3372. Maximize the Number of Target Nodes After Connecting Trees I
    There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.
    You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.
    Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.
    Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.
    Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

    Example :
    Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2
    Output: [9,7,9,8,8]
    Explanation:
    For i = 0, connect node 0 from the first tree to node 0 from the second tree.
    For i = 1, connect node 1 from the first tree to node 0 from the second tree.
    For i = 2, connect node 2 from the first tree to node 4 from the second tree.
    For i = 3, connect node 3 from the first tree to node 4 from the second tree.
    For i = 4, connect node 4 from the first tree to node 4 from the second tree.
"""


from collections import defaultdict
from typing import List
class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        n = len(edges1) + 1
        m = len(edges2) + 1
        
        def build_adj(edges):
            adj = defaultdict(list)
            for u, v in edges:
                adj[u].append(v)
                adj[v].append(u)
            return adj

        def DFS(u, parent, max_len, adj):
            if max_len < 0:
                return 0
            count = 1
            for v in adj[u]:
                if v != parent:
                    count += DFS(v, u, max_len - 1, adj)
            return count
        
        adj1 = build_adj(edges1)
        adj2 = build_adj(edges2)

        max_cnt2 = 0
        for i in range(m):
            max_cnt2 = max(max_cnt2, DFS(i, -1, k - 1, adj2))

        res = []
        
        for i in range(n):
            count = DFS(i, -1, k, adj1)
            res.append(count + max_cnt2)
        return res