"""
2658. Maximum Number of Fish in a Grid
    You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

    A land cell if grid[r][c] = 0, or
    A water cell containing grid[r][c] fish, if grid[r][c] > 0.
    A fisher can start at any water cell (r, c) and can do the following operations any number of times:
    Catch all the fish at cell (r, c), or
    Move to any adjacent water cell.
    Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
    An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

    Example :
    Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
    Output: 7
    Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
"""

from typing import List
class Solution:
    def __init__(self):
        self.d = [0, 1, 0, -1, 0]
        self.r = 0
        self.c = 0

    def DFS(self, i, j, grid):
        fish = grid[i][j]
        grid[i][j] = 0
        for a in range(4):
            row = i + self.d[a]
            col = j + self.d[a + 1]
            if row < 0 or row >= self.r or col < 0 or col >= self.c or grid[row][col] == 0:
                continue
            fish += self.DFS(row, col, grid)
        return fish

    def findMaxFish(self, grid: List[List[int]]) -> int:
        self.r = len(grid)
        self.c = len(grid[0])
        ans = 0
        for i in range(self.r):
            for j in range(self.c):
                if grid[i][j] > 0:
                    ans = max(ans, self.DFS(i, j, grid))

        return ans