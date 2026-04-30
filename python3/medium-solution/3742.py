"""
3742. Maximum Path Score in a Grid
    You are given an m x n grid where each cell contains one of the values 0, 1, or 2. You are also given an integer k.
    You start from the top-left corner (0, 0) and want to reach the bottom-right corner (m - 1, n - 1) by moving only right or down.
    Each cell contributes a specific score and incurs an associated cost, according to their cell values:
    0: adds 0 to your score and costs 0.
    1: adds 1 to your score and costs 1.
    2: adds 2 to your score and costs 1.
    Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.
    Note: If you reach the last cell but the total cost exceeds k, the path is invalid.

    Example :
    Input: grid = [[0, 1],[2, 0]], k = 1
    Output: 2
    Explanation:
    The optimal path is:
    Cell	grid[i][j]	Score	Total
    Score	Cost	Total
    Cost
    (0, 0)	0	0	0	0	0
    (1, 0)	2	2	2	1	1
    (1, 1)	0	0	2	0	1
    Thus, the maximum possible score is 2.
"""

from typing import List

class Solution:
    def maxPathScore(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [{} for _ in range(n)]
        dp[0][k] = 0
        for i in range(m):
            for j in range(n):
                curr = grid[i][j]
                left = dp[j - 1].copy() if j > 0 else {}
                upper = dp[j].copy()
                res = {}
                for k, v in upper.items():
                    if (k in left and left[k] < v) or (k not in left):
                        left[k] = v
                
                if curr != 0:
                    for k, v in left.items():
                        if k >= 1:
                            res[k - 1] = v + curr
                else:
                    res = left
                dp[j] = res
        return max(dp[n - 1].values()) if len(dp[n - 1]) != 0 else -1