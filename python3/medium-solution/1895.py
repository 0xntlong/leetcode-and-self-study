"""
1895. Largest Magic Square
    A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.
    Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.

    Example:
    Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
    Output: 3
    Explanation: The largest magic square has a size of 3.
    Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
    - Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
    - Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
    - Diagonal sums: 5+4+3 = 6+4+2 = 12
"""

from typing import List

class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        r, c = len(grid), len(grid[0])
        rowSum = [[0] * (c + 1) for _ in range(r + 1)]
        colSum = [[0] * (c + 1) for _ in range(r + 1)]
        diag = [[0] * (c + 1) for _ in range(r + 1)]
        antidiag = [[0] * (c + 1) for _ in range(r + 1)]

        for i in range(r):
            for j in range(c):
                x = grid[i][j]
                rowSum[i + 1][j + 1] = rowSum[i + 1][j] + x
                colSum[i + 1][j + 1] = colSum[i][j + 1] + x
                diag[i + 1][j + 1] = diag[i][j] + x
                antidiag[i + 1][j] = antidiag[i][j + 1] + x
        def isMagic(k : int) -> bool:
            for i in range(r - k + 1):
                for j in range(c - k + 1):
                    s = diag[i + k][j + k] - diag[i][j]
                    anti = antidiag[i + k][j] - antidiag[i][j + k]
                    if s != anti:
                        continue
                    valid = True
                    for m in range(k):
                        row = rowSum[i + m + 1][j + k] - rowSum[i + m + 1][j]
                        col = colSum[i + k][j + m + 1] - colSum[i][j + m + 1]
                        if row != s or col != s:
                            valid = False
                            break
                    if valid:
                        return True
            return False
        for k in range(min(r, c), 1, -1):
            if isMagic(k):
                return k
        return 1