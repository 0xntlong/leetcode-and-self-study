"""
2906. Construct Product Matrix
    Given a 0-indexed 2D integer matrix grid of size n * m, we define a 0-indexed 2D matrix p of size n * m as the product matrix of grid if the following condition is met:
    Each element p[i][j] is calculated as the product of all elements in grid except for the element grid[i][j]. This product is then taken modulo 12345.
    Return the product matrix of grid.

    Example :
    Input: grid = [[1,2],[3,4]]
    Output: [[24,12],[8,6]]
    Explanation: p[0][0] = grid[0][1] * grid[1][0] * grid[1][1] = 2 * 3 * 4 = 24
    p[0][1] = grid[0][0] * grid[1][0] * grid[1][1] = 1 * 3 * 4 = 12
    p[1][0] = grid[0][0] * grid[0][1] * grid[1][1] = 1 * 2 * 4 = 8
    p[1][1] = grid[0][0] * grid[0][1] * grid[1][0] = 1 * 2 * 3 = 6
    So the answer is [[24,12],[8,6]].
"""



from typing import List



class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        """
        n = len(grid)
        m = len(grid[0])
        zero = 0
        total = 1
        mod = 12345
        for i in range(n):
            for j in range(m):
                grid[i][j] %= mod
                if grid[i][j] == 0:
                    zero += 1
                else:
                    total = total * grid[i][j]

        for i in range(n):
            for j in range(m):
                if zero > 1:
                    grid[i][j] = 0
                elif zero == 1:
                    if grid[i][j]:
                        grid[i][j] = 0
                    else:
                        grid[i][j] = total % mod
                else:
                    grid[i][j] = (total // grid[i][j]) % mod
        return grid
        """
        
        n = len(grid)
        m = len(grid[0])
        zero = 0
        total = 1
        dp = [[0] * m for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                dp[i][j] = total
                total = (total * grid[i][j]) % 12345
        total = 1
        for i in range(n):
            for j in range(m):
                dp[i][j] = (dp[i][j] * total) % 12345
                total = (total * grid[i][j]) % 12345
        return dp