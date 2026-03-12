"""
3600. Maximize Spanning Tree Stability with Upgrades
    You are given an integer n, representing n nodes numbered from 0 to n - 1 and a list of edges, where edges[i] = [ui, vi, si, musti]:
    ui and vi indicates an undirected edge between nodes ui and vi.
    si is the strength of the edge.
    musti is an integer (0 or 1). If musti == 1, the edge must be included in the spanning tree. These edges cannot be upgraded.
    You are also given an integer k, the maximum number of upgrades you can perform. Each upgrade doubles the strength of an edge, and each eligible edge (with musti == 0) can be upgraded at most once.
    The stability of a spanning tree is defined as the minimum strength score among all edges included in it.
    Return the maximum possible stability of any valid spanning tree. If it is impossible to connect all nodes, return -1.
    Note: A spanning tree of a graph with n nodes is a subset of the edges that connects all nodes together (i.e. the graph is connected) without forming any cycles, and uses exactly n - 1 edges.

    Example :

    Input: n = 3, edges = [[0,1,2,1],[1,2,3,0]], k = 1

    Output: 2

    Explanation:

    Edge [0,1] with strength = 2 must be included in the spanning tree.
    Edge [1,2] is optional and can be upgraded from 3 to 6 using one upgrade.
    The resulting spanning tree includes these two edges with strengths 2 and 6.
    The minimum strength in the spanning tree is 2, which is the maximum possible stability.
"""



from typing import List


class Solution:
    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        parent = list(range(n))
        size = [1] * n
        def find(v):
            if parent[v] == v:
                return v
            parent[v] = find(parent[v])
            return parent[v]
        def union(a, b):
            a = find(a)
            b = find(b)
            if a != b:
                if size[a] < size[b]:
                    a, b = b, a
                parent[b] = a
                size[a] += size[b]
                return True
            return False
        comp = n
        res = float("inf")
        opt = []
        for idx, edge in enumerate(edges):
            if edge[3] == 1:
                if union(edge[0], edge[1]):
                    comp -= 1
                    res = min(res, edge[2]) 
                else:
                    return -1  
        if comp == 1:  
            return res
        opt = [idx for idx, edge in enumerate(edges) if edge[3] == 0]
        opt.sort(key=lambda x: edges[x][2], reverse=True)
        stab = [] 
        for i in opt:
            edge = edges[i]
            if union(edge[0], edge[1]):
                comp -= 1
                stab.append(edge[2]) 
                if comp == 1:  
                    break
        if comp > 1: 
            return -1
        for i in range(1, min(len(stab), k) + 1):
            stab[-i] *= 2  
        return min(min(stab, default=res), res)