"""
2290. Minimum Obstacle Removals to Reach Corner
    You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:
    0 represents an empty cell,
    1 represents an obstacle that may be removed.
    You can move up, down, left, or right from and to an empty cell.
    Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).

    Example :
    Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
    Output: 2
    Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
    It can be shown that we need to remove at least 2 obstacles, so we return 2.
    Note that there may be other ways to remove 2 obstacles to create a path.
"""

from typing import List
from collections import deque
class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        Rows = len(grid)
        Cols = len(grid[0])
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        q = deque([(0, (0, 0))])
        visited = set()
        while q:
            dist, (row, col) = q.popleft()
            if (row, col) == (Rows - 1, Cols - 1):
                return dist
            if (row, col) in visited:
                continue
            visited.add((row, col))
            for dirR, dirC in directions:
                dx, dy = row + dirR, col + dirC
                if dx in range(Rows) and dy in range(Cols) and (dx, dy) not in visited:
                    if grid[dx][dy] == 1:
                        q.append((dist + 1, (dx, dy)))
                    else:
                        q.appendleft((dist, (dx, dy)))
        return -1