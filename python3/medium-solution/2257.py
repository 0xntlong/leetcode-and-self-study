"""
2257. Count Unguarded Cells in the Grid
    You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
    A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.
    Return the number of unoccupied cells that are not guarded.

    Example :
    Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
    Output: 7
    Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
    There are a total of 7 unguarded cells, so we return 7.
"""

from typing import List
class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [[0] * n for _ in range(m)]
        for r, c in walls:
            grid[r][c] = 2
        for r, c in guards:
            grid[r][c] = 2
        for x, y in guards:
            for r in range(x + 1, m):
                if grid[r][y] == 2:
                    break
                grid[r][y] = 1
            for r in range(x - 1, -1, -1):
                if grid[r][y] == 2:
                    break
                grid[r][y] = 1
            for c in range(y + 1, n):
                if grid[x][c] == 2:
                    break
                grid[x][c] = 1
            for c in range(y - 1, -1, -1):
                if grid[x][c] == 2:
                    break
                grid[x][c] = 1
        res = 0
        for r in range(m):
            for c in range(n):
                res += not grid[r][c]
        return res