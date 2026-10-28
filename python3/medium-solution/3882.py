"""
3882. Minimum XOR Path in a Grid
    You are given a 2D integer array grid of size m * n.
    You start at the top-left cell (0, 0) and want to reach the bottom-right cell (m - 1, n - 1).
    At each step, you may move either right or down.
    The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, including the start and end cells.
    Return the minimum possible XOR value among all valid paths from (0, 0) to (m - 1, n - 1).

    Example :
    Input: grid = [[1,2],[3,4]]
    Output: 6
    Explanation:
    There are two valid paths:
    (0, 0) → (0, 1) → (1, 1) with XOR: 1 XOR 2 XOR 4 = 7
    (0, 0) → (1, 0) → (1, 1) with XOR: 1 XOR 3 XOR 4 = 6
    The minimum XOR value among all valid paths is 6.
"""


class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])

        dp = [set() for _ in range(n)]
        dp[0].add(grid[0][0])

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue

                value = grid[i][j]
                reachable = dp[j] | (dp[j - 1] if j > 0 else set())

                dp[j] = {k ^ value for k in reachable}

        return min(dp[-1])