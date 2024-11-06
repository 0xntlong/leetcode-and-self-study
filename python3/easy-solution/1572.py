"""
1572. Matrix Diagonal Sum
    Given a square matrix mat, return the sum of the matrix diagonals.
    Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
    
    Example 1:
    Input: mat = [[1,2,3],
                 [4,5,6],
                 [7,8,9]]
    Output: 25
    Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
    Notice that element mat[1][1] = 5 is counted only once.
    
    Example 2:
    Input: mat = [[1,1,1,1],
                 [1,1,1,1],
                 [1,1,1,1],
                 [1,1,1,1]]
    Output: 8
"""

from typing import List
class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        res = 0
        for i in range(n):
            res += mat[i][i] + mat[i][n - i - 1]
        if n % 2 == 1:
            res -= mat[n // 2][n // 2]
        return res             