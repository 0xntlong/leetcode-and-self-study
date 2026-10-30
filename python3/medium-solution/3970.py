"""
3970. Shortest Path With At Most K Consecutive Identical Characters
    You are given an integer n representing the number of nodes in a directed weighted graph, numbered from 0 to n - 1. This is represented by a 2D integer array edges, where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with weight wi.
    You are also given a string labels of length n, where labels[i] is the character assigned to node i, and an integer k.
    Return the minimum total edge weight of a path from node 0 to node n - 1 such that the concatenation of the labels of the nodes along the path contains at most k consecutive identical characters. If no valid path exists, return -1.

    Example :
    Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 1
    Output: 3
    Explanation:
    The optimal valid path from node 0 to node 2 is as follows:
    Use edges[2] = [0, 2, 3] to reach node 2 with a weight wi = 3.
    The corresponding concatenation of labels is "ab", which satisfies at most k = 1 consecutive identical characters. Thus, the answer is 3.
"""


from heapq import heappop, heappush
from typing import List
class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        graph = [[] for _ in range(n)]
        for u, v, w in edges:
            graph[u].append((v, w, labels[u] == labels[v]))

        done = [k + 1] * n  
        heap = [(0, 0, 1)]
        last = n - 1

        while heap:
            d, u, r = heappop(heap)
            if r >= done[u]: 
                continue
            done[u] = r
            if u == last:
                return d
            for v, w, same in graph[u]:
                nr = r + 1 if same else 1
                if nr < done[v]: 
                    heappush(heap, (d + w, v, nr))

        return -1