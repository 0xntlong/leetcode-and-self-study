"""
2661. First Completely Painted Row or Column
    You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
    Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
    Return the smallest index i at which either a row or a column will be completely painted in mat.
    Example :
    image explanation for example 1
    Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
    Output: 2
    Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
"""

from typing import List
class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        N = m * n
        to_i = [0] * (N + 1)
        to_j = [0] * (N + 1)
        for i in range(m):
            for j in range(n):
                matrix = mat[i][j]
                to_i[matrix] = i
                to_j[matrix] = j
        
        row = [0] * m
        col = [0] * n
        for i in range(N):
            matrix = arr[i]
            row[to_i[matrix]] += 1
            col[to_j[matrix]] += 1
            if row[to_i[matrix]] == n or col[to_j[matrix]] == m:
                return i
        
        return -1
