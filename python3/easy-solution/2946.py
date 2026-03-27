"""
2946. Matrix Similarity After Cyclic Shifts
    You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.
    The following proccess happens k times:
    Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.
    Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.

    Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.

    Example 1:
    Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4
    Output: false
    Explanation:
    In each step left shift is applied to rows 0 and 2 (even indices), and right shift to row 1 (odd index).
"""

from typing import List

class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        rows = len(mat)
        cols = len(mat[0])
        k %= cols  
        if k == 0:
            return True  
        
        for i in range(rows):
            shifted_row = mat[i][k:] + mat[i][:k]
            
            if mat[i] != shifted_row:
                return False
        
        return True