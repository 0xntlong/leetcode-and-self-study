"""
3243. Shortest Distance After Road Addition Queries I
    You are given an integer n and a 2D integer array queries.
    There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.
    queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.
    Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.

    Example :
    Input: n = 5, queries = [[2,4],[0,2],[0,4]]
    Output: [3,2,1]
    Explanation:
    After the addition of the road from 2 to 4, the length of the shortest path from 0 to 4 is 3.
    After the addition of the road from 0 to 2, the length of the shortest path from 0 to 4 is 2.
    After the addition of the road from 0 to 4, the length of the shortest path from 0 to 4 is 1.
"""

from typing import List
class Solution:
    def dfs (self, tree, c, dp):
        d = dp[c] + 1
        for x in tree[c]:
            if dp[x] <= d:
                continue
            dp[x] = d
            self.dfs(tree, x, dp) 
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        dp = [n - 1 - i for i in range(n)]
        tree = [[] for _ in range(n)]
        for i in range(n - 1):
            tree[i + 1].append(i)
        res = []
        for q in queries:
            a, b = q[0], q[1]
            tree[b].append(a)
            dp[a] = min(dp[a], dp[b] + 1)
            self.dfs(tree, a, dp)
            res.append(dp[0])
        return res 