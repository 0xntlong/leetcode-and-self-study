"""
1857. Largest Color Value in a Directed Graph
    There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
    You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
    A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
    Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

    Example :
    Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
    Output: 3
    Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
"""

from collections import defaultdict
from typing import List
class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        adj = defaultdict(list)
        for u, v in edges:
            adj[u].append(v)

        freq = [[0] * 26 for _ in range(n)]
        visited = [0] * n
        cycle = [0] * n
        
        def DFS(i):
            if cycle[i]:
                return float('inf')
            if visited[i]:
                return freq[i][ord(colors[i]) - ord('a')]
            visited[i] = cycle[i] = 1
            for j in adj[i]:
                if DFS(j) == float('inf'):
                    return float('inf')
                for x in range(26):
                    freq[i][x] = max(freq[i][x], freq[j][x])
            cycle[i] = 0
            freq[i][ord(colors[i]) - ord('a')] += 1
            return freq[i][ord(colors[i]) - ord('a')]
        ans = 0
        for u in range(n):
            val = DFS(u)
            if val == float('inf'):
                return -1
            ans = max(ans, val)
        return ans