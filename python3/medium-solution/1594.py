"""
1594. Maximum Non Negative Product in a Matrix
    You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.
    Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.
    Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.
    Notice that the modulo is performed after getting the maximum product.
    Example :
    Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
    Output: -1
    Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
"""


from cmath import inf
    


class Solution:
    def maxProductPath(self, grid):
        m, n = len(grid), len(grid[0])
        MOD = 10**9 + 7

        Min = [[inf] * n for _ in range(m)]
        Max = [[-inf] * n for _ in range(m)]
        Min[0][0], Max[0][0] = grid[0][0], grid[0][0]
        for i in range(m):
            for j in range(n):
                if  i == 0 and j == 0:
                    continue
                Min[i][j] = min(
                    Min[i - 1][j] * grid[i][j] if i > 0 else inf,
                    Max[i - 1][j] * grid[i][j] if i > 0 else inf,
                    Min[i][j - 1] * grid[i][j] if j > 0 else inf,
                    Max[i][j - 1] * grid[i][j] if j > 0 else inf
                )
                Max[i][j] = max(
                    Min[i - 1][j] * grid[i][j] if i > 0 else -inf,
                    Max[i - 1][j] * grid[i][j] if i > 0 else -inf,
                    Min[i][j - 1] * grid[i][j] if j > 0 else -inf,
                    Max[i][j - 1] * grid[i][j] if j > 0 else -inf
                )
            
        res = Max[-1][-1]
        return res % MOD if res >= 0 else -1