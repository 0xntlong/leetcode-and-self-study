"""
3534. Path Existence Queries in a Graph II
    You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.
    You are also given an integer array nums of length n and an integer maxDiff.
    An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).
    You are also given a 2D integer array queries. For each queries[i] = [ui, vi], find the minimum distance between nodes ui and vi. If no path exists between the two nodes, return -1 for that query.
    Return an array answer, where answer[i] is the result of the ith query.
    Note: The edges between the nodes are unweighted.

    Example:
    Input: n = 5, nums = [1,8,3,4,2], maxDiff = 3, queries = [[0,3],[2,4]]
    Output: [1,1]
    Explanation:
    The resulting graph is:

    Query	Shortest Path	Minimum Distance
    [0, 3]	0 → 3	1
    [2, 4]	2 → 4	1
    Thus, the output is [1, 1].
 """



from typing import List

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        LOG = 18
        vec = []
        for i in range(n):
            vec.append((nums[i], i))
        vec.sort()

        getSortIdx = [0] * n
        for i in range(n):
            getSortIdx[vec[i][1]] = i

        st = [[0] * LOG for _ in range(n)]
        l = 0

        for r in range(n):
            while vec[r][0] - vec[l][0] > maxDiff:
                st[l][0] = r - 1
                l += 1

        while l < n:
            st[l][0] = n - 1
            l += 1

        for j in range(1, LOG):
            for i in range(n):
                st[i][j] = st[st[i][j - 1]][j - 1]

        ans = [-1] * len(queries)

        for i in range(len(queries)):
            a = getSortIdx[queries[i][0]]
            b = getSortIdx[queries[i][1]]

            if a > b:
                a, b = b, a
            if a == b:
                ans[i] = 0
                continue

            cur = a
            step = 0

            for j in range(LOG - 1, -1, -1):
                if st[cur][j] < b:
                    step += 1 << j
                    cur = st[cur][j]

            if st[cur][0] >= b:
                ans[i] = step + 1

        return ans