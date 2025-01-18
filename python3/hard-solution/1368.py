"""
1368. Minimum Cost to Make at Least One Valid Path in a Grid
    Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:
    1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
    2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
    3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
    4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
    Notice that there could be some signs on the cells of the grid that point outside the grid.
    You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.
    You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.
    Return the minimum cost to make the grid have at least one valid path.

    Example :
    Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
    Output: 3
    Explanation: You will start at point (0, 0).
    The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
    The total cost = 3.
"""

from heapq import heappop, heappush
from typing import List

class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        cost = [[float('inf')] * m for _ in range(n)]
        pq = [(0, 0, 0)]
        cost[0][0] = 0

        while pq:
            curCost, x, y = heappop(pq)
            if x == n - 1 and y == m - 1:
                return curCost
            dir = grid[x][y] - 1
            for i, (dx, dy) in enumerate(directions):
                newX, newY = x + dx, y + dy
                if 0 <= newX < n and 0 <= newY < m:
                    newCost = curCost + ( i != dir)
                    if newCost < cost[newX][newY]:
                        cost[newX][newY] = newCost
                        heappush(pq, (newCost, newX, newY))
        return -1