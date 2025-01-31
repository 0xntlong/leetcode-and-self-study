"""
827. Making A Large Island
    You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
    Return the size of the largest island in grid after applying this operation.
    An island is a 4-directionally connected group of 1s.

    Example :
    Input: grid = [[1,0],[0,1]]
    Output: 3
    Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
"""

from typing import List

class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        islandId = 2 
        sz = {}
        def DFS(r, c, id):
            grid[r][c] = id
            size = 1
             
            if r > 0 and grid[r - 1][c] == 1:
                size += DFS(r - 1, c, id)
            if c > 0 and grid[r][c - 1] == 1:
                size += DFS(r, c - 1, id)
            if r < n - 1 and grid[r + 1][c] == 1:
                size += DFS(r + 1, c, id)
            if c < n - 1 and grid[r][c + 1] == 1:
                size += DFS(r, c + 1, id)
            return size

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    ts = DFS(i, j, islandId)
                    sz[islandId] = ts
                    islandId += 1

        if not sz:
            return 1

        res = max(sz.values())

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    unique_island = set()
                    p = 1
                    if i > 0 and grid[i -1][j] > 1:
                        t = grid[i - 1][j]
                        if t in sz and t not in unique_island:
                            p += sz[t]
                            unique_island.add(t)
                    if j > 0 and grid[i][j - 1] > 1:
                        t = grid[i][j -1]
                        if t in sz and t not in unique_island:
                            p += sz[t]
                            unique_island.add(t)

                    if i < n - 1 and grid[i + 1][j] > 1:
                        t = grid[i + 1][j]
                        if t in sz and t not in unique_island:
                            p += sz[t]
                            unique_island.add(t)
                    
                    if j < n - 1 and grid[i][j + 1] > 1:
                        t = grid[i][j + 1]
                        if t in sz and t not in unique_island:
                            p += sz[t]
                            unique_island.add(t)

                    res = max(res, p)
        
        return res