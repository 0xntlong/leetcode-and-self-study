"""
3197. Find the Minimum Area to Cover All Ones II
    You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.
    Return the minimum possible sum of the area of these rectangles.
    Note that the rectangles are allowed to touch.

    Example :
    Input: grid = [[1,0,1],[1,1,1]]
    Output: 5
    Explanation:
    The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
    The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
    The 1 at (1, 1) is covered by a rectangle of area 1.
"""


from typing import List


class Solution:
    def minimumSum(self, grid: List[List[int]]) -> int:
        res = float("inf")
        for _ in range(4):
            m, n = len(grid), len(grid[0])
            for i in range(1, m):
                mnGrid = self.area(grid[:i])
                for j in range(1, n):
                    left = [row[:j] for row in grid[i:]]
                    right = [row[j:] for row in grid[i:]]
                    grid2 = self.area(left)
                    grid3 = self.area(right)
                    res = min(res,mnGrid + grid2 + grid3)
                for k in range(i + 1, m):
                    best2 = grid[i:k]
                    best3 = grid[k:]
                    grid2 = self.area(best2)
                    grid3 = self.area(best3)
                    res = min(res, grid2 + grid3 + mnGrid)
            grid = self.rotate(grid)
        return res
    def area(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        m, n = len(grid), len(grid[0])
        left, top, right, bottom = float("inf"), float("inf"), -1, -1
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    left = min(left, j)
                    right = max(right, j)
                    top = min(top, i)
                    bottom = max(bottom, i)
        if right == -1:
            return 0
        return (right - left + 1) * (bottom - top + 1)
    
    def rotate(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        return [[grid[i][j] for i in range(m - 1, -1, -1)] for j in range(n)]