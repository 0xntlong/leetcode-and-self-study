"""
2503. Maximum Number of Points From Grid Queries
    You are given an m x n integer matrix grid and an array queries of size k.
    Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:
    If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
    Otherwise, you do not get any points, and you end this process.
    After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
    Return the resulting array answer.

    Example :
    Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
    Output: [5,8,1]
    Explanation: The diagrams above show which cells we visit to get points for each query.
"""

from heapq import heappop, heappush
from typing import List

class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        m, n = len(grid), len(grid[0])
        res = [0] * len(queries)

        heap = [(grid[0][0], 0, 0)]
        directions = [(-1, 0), (0, 1), (0, -1), (1, 0)]
        grid[0][0] = 0
        cnt = 0

        for qi, q in sorted(enumerate(queries), key=lambda x: x[1]):
            while heap and heap[0][0] < q:
                _, i, j = heappop(heap)
                cnt += 1
                for di, dj in directions:
                    inew, jnew = i+di, j+dj
                    if inew>=0 and inew<m and jnew>=0 and jnew<n and grid[inew][jnew]:
                        heappush(heap, (grid[inew][jnew], inew, jnew))
                        grid[inew][jnew] = 0
            res[qi] = cnt
        return res