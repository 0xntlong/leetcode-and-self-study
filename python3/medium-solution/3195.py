"""
3195. Find the Minimum Area to Cover All Ones I
    You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.
    Return the minimum possible area of the rectangle.

    Example :

    Input: grid = [[0,1,0],[1,0,1]]
    Output: 6
    Explanation:
    The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.
"""

from typing import List

class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        minRow = 1000
        maxRow = -1
        minCol = 1000
        maxCol = -1
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    minRow = min(minRow, i)
                    maxRow = max(maxRow, i)
                    minCol = min(minCol, j)
                    maxCol = max(maxCol, j)
        return (maxRow - minRow + 1) * (maxCol - minCol + 1)