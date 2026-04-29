"""
3225. Maximum Score From Grid Operations
    You are given a 2D matrix grid of size n x n. Initially, all cells of the grid are colored white. In one operation, you can select any cell of indices (i, j), and color black all the cells of the jth column starting from the top row down to the ith row.
    The grid score is the sum of all grid[i][j] such that cell (i, j) is white and it has a horizontally adjacent black cell.
    Return the maximum score that can be achieved after some number of operations.
    Example :
    Input: grid = [[0,0,0,0,0],[0,0,3,0,0],[0,1,0,0,0],[5,0,0,3,0],[0,0,0,0,2]]
    Output: 11
    Explanation:
    In the first operation, we color all cells in column 1 down to row 3, and in the second operation, we color all cells in column 4 down to the last row. The score of the resulting grid is grid[3][0] + grid[1][2] + grid[3][3] which is equal to 11.
"""
from typing import List


class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if n == 1:
            return 0
        dp0 = [0] * (n + 1)
        dp1 = [0] * (n + 1)
        for j in range(1, n):
            new_dp0 = [0] * (n + 1)
            new_dp1 = [0] * (n + 1)
            for i in range(n + 1):
                prev = 0
                curr = sum(grid[x][j] for x in range(i))
                for y in range(n + 1):
                    if y > 0 and y <= i:
                        curr -= grid[y - 1][j]
                    if j > 0 and y > i:
                        prev += grid[y - 1][j - 1]
                    new_dp0[y] = max(new_dp0[y], prev + dp0[i], dp1[i])
                    new_dp1[y] = max(new_dp1[y], curr + dp1[i], curr + prev + dp0[i])
            dp0, dp1 = new_dp0, new_dp1
        return max(dp1)