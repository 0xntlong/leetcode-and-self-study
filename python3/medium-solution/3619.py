"""
3619. Count Islands With Total Value Divisible by K
    You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally or vertically).
    The total value of an island is the sum of the values of all cells in the island.
    Return the number of islands with a total value divisible by k.

    Example :
    Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5
    Output: 2
    Explanation:
    The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.
"""

from collections import deque
from typing import List

class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])

        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    continue
                
                queue = deque([(i, j)])
                curr = grid[i][j]
                grid[i][j] = 0
                while queue:
                    pi, pj = queue.popleft()

                    for di, dj in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                        ni = pi + di
                        nj = pj + dj

                        if not (0 <= ni < m and 0 <= nj < n):
                            continue
                        if grid[ni][nj] == 0:
                            continue

                        curr += grid[ni][nj]
                        grid[ni][nj] = 0
                        queue.append((ni, nj))
                
                if curr % k == 0:
                    count += 1

        return count
