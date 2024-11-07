"""
1582. Special Positions in a Binary Matrix
    Given an m x n binary matrix mat, return the number of special positions in mat.
    A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

    Example :
    Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
    Output: 1
    Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
"""

from typing import List
class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        x = len(mat)
        y = len(mat[0])
        res = 0
        for row in range(x):
            for col in range(y):
                if mat[row][col] == 0:
                    continue
                good = True
                for r in range(x):
                    if r != row and mat[r][col] == 1:
                        good = False
                        break
                for c in range(y):
                    if c != col and mat[row][c] == 1:
                        good = False
                        break
                if good:
                    res += 1
        return res