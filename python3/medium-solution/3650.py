"""
3650. Minimum Cost Path with Edge Reversals
    You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.
    Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.
    The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.
    Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

    Example :
    Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]
    Output: 5
    Explanation:
    Use the path 0 → 1 (cost 3).
    At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2.
    Total cost is 3 + 2 = 5.
"""

from typing import List
import heapq

class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for u, v, w in edges:
            graph[u].append((v, w))
            graph[v].append((u, 2 * w))

        ans = [float("inf")] * n
        ans[0] = 0
        pq = [(0, 0)]  

        while pq:
            weight, node = heapq.heappop(pq)
            if weight > ans[node]:
                continue

            for nd, wt in graph[node]:
                if wt + weight < ans[nd]:
                    ans[nd] = wt + weight
                    heapq.heappush(pq, (ans[nd], nd))

        return -1 if ans[n - 1] == float("inf") else ans[n - 1]