"""
790. Domino and Tromino Tiling
    You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
    Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.
    In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

    Example :
    Input: n = 3
    Output: 5
    Explanation: The five different ways are show above.
"""



class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 10**9 + 7
        dp = [1, 1, 2]
        if n == 1:
            return 1
        if n == 2:
            return 2
        if n == 0:
            return 0
        for i in range(3, n + 1):
            dp_value = (dp[i - 3] + 2 * dp[i - 1]) % MOD
            dp.append(dp_value)
        return dp[-1]