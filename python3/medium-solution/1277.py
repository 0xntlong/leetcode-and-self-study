"""
1277. Count Square Submatrices with All Ones
    Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

    Example :
    Input: matrix =
    [
    [0,1,1,1],
    [1,1,1,1],
    [0,1,1,1]
    ]
    Output: 15
    Explanation: 
    There are 10 squares of side 1.
    There are 4 squares of side 2.
    There is  1 square of side 3.
    Total number of squares = 10 + 4 + 1 = 15.
"""
from collections import defaultdict
from typing import List

# IRST APPROACH
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        ROW = len(matrix)
        COL = len(matrix[0])
        dp = [[0] * COL for _ in range(ROW)]
        result = 0
        for x in range(ROW):
            for y in range(COL):
                if matrix[x][y] == 1:
                    dp[x][y] = 1
                    if x - 1 >= 0 and y - 1 >= 0:
                        dp[x][y] = min(
                            dp[x -1][y],
                            dp[x -1][y -1],
                            dp[x][y -1]
                        ) + 1
                    result += dp[x][y]

        return result
    
# SECOND APPROACH

class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        ROW = len(matrix)
        COL = len(matrix[0])
        dp = defaultdict(int)
        result = 0
        for x in range(ROW):
            cur_dp = defaultdict(int)
            for y in range(COL):
                if matrix[x][y]:
                    cur_dp[y] = 1 + min(
                        dp[y],
                        cur_dp[y-1],
                        dp[y-1]
                    )
                    result += cur_dp[y]
            dp = cur_dp
        return result