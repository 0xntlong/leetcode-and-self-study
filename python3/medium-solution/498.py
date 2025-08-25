"""
498. Diagonal Traverse
    Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

    Example 1:
    Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,4,7,5,3,6,8,9]
"""


from typing import List
class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        m = len(mat)
        n = len(mat[0])
        res = []
        i, j = 0, 0
        direction = 1
        for _ in range(m * n):
            res.append(mat[i][j])
            if direction == 1:
                if j == n - 1:
                    i += 1
                    direction = -1
                elif i == 0:
                    j += 1
                    direction = -1
                else:
                    i -= 1
                    j += 1
            else:
                if i == m - 1:
                    j += 1
                    direction = 1
                elif j == 0:
                    i += 1
                    direction = 1
                else:
                    i += 1
                    j -= 1
        return res