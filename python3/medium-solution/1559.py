"""
1559. Detect Cycles in 2D Grid
    Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.
    A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.
    Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.
    Return true if any cycle of the same value exists in grid, otherwise, return false.


    Example 1:
    Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
    Output: true
    Explanation: There are two valid cycles shown in different colors in the image below:
"""

from typing import List

class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        rows, cols = len(grid), len(grid[0])
        parent = list(range(rows * cols))
        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        
        def union(a, b):
            ra, rb = find(a), find(b)
            if ra == rb:
                return True
            parent[ra] = rb
            return False
        
        for i in range(rows):
            for j in range(cols):
                if j + 1 < cols and grid[i][j] == grid[i][j + 1]:
                    if union(i * cols + j, i * cols + j + 1):
                        return True
                if i + 1 < rows and grid[i][j] == grid[i + 1][j]:
                    if union(i * cols + j, (i + 1) * cols + j):
                        return True
        return False