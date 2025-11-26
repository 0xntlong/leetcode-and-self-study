"""
2435. Paths in Matrix Whose Sum Is Divisible by K
    You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.
    Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 109 + 7.

    Example :
    Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
    Output: 2
    Explanation: There are two paths where the sum of the elements on the path is divisible by k.
    The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
    The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.
"""


from typing import List
 
class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        mod = 10**9 + 7
        dp = [[[0] * k for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    dp[i][j][grid[i][j] % k] += 1
                elif i == 0:
                    for x in range(k):
                        dp[i][j][(x + grid[i][j]) % k] += dp[i][j - 1][x] % mod
                elif j == 0:
                    for x in range(k):
                        dp[i][j][(x + grid[i][j]) % k] += dp[i - 1][j][x] % mod 
                else:
                    for x in range(k):
                        dp[i][j][(x + grid[i][j]) % k] += dp[i][j - 1][x] % mod 
                        dp[i][j][(x + grid[i][j]) % k] += dp[i - 1][j][x] % mod 
        return dp[m - 1][n - 1][0] % mod