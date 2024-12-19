"""
2133. Check if Every Row and Column Contains All Numbers
    An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).
    Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.

    Example :
    Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
    Output: true
    Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
    Hence, we return true.
"""

from typing import List
class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        n = len(matrix)
        for i in range(n):
            row, col = set(), set()
            for j in range(n):
                row.add(matrix[i][j])
                col.add(matrix[j][i])
            if len(row) != n or len(col) != n:
                return False
        return True