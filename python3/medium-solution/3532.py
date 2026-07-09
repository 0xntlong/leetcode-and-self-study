"""
3532. Path Existence Queries in a Graph I
    You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.
    You are also given an integer array nums of length n sorted in non-decreasing order, and an integer maxDiff.
    An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).
    You are also given a 2D integer array queries. For each queries[i] = [ui, vi], determine whether there exists a path between nodes ui and vi.
    Return a boolean array answer, where answer[i] is true if there exists a path between ui and vi in the ith query and false otherwise.
    
    Example :
    Input: n = 2, nums = [1,3], maxDiff = 1, queries = [[0,0],[0,1]]
    Output: [true,false]
    Explanation:
    Query [0,0]: Node 0 has a trivial path to itself.
    Query [0,1]: There is no edge between Node 0 and Node 1 because |nums[0] - nums[1]| = |1 - 3| = 2, which is greater than maxDiff.
    Thus, the final answer after processing all the queries is [true, false].
"""

from typing import List
class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        dp = [0] * n
        cnt = 0
        for i in range(1, n):
            if nums[i] - nums[i - 1] > maxDiff:
                cnt += 1
            dp[i] = cnt
        return [dp[u] == dp[v] for u, v in queries]