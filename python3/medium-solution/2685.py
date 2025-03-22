"""
2685. Count the Number of Complete Components
    You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.
    Return the number of complete connected components of the graph.
    A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
    A connected component is said to be complete if there exists an edge between every pair of its vertices.

    Example :
    Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
    Output: 3
    Explanation: From the picture above, one can see that all of the components of this graph are complete.
"""

from typing import List

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        X = [[] for i in range(n)]
        for u, v in edges:
            X[u].append(v)
            X[v].append(u)

        visited = [0] * n
        res = 0
        for i in range(n):
            if visited[i]:
                continue
            bfs = [i]
            visited[i] = 1
            for j in bfs:
                for k in X[j]:
                    if visited[k] == 0:
                        bfs.append(k)
                        visited[k] = 1
            if all(len(X[j]) == len(bfs) - 1 for j in bfs):
                res += 1
        return res
