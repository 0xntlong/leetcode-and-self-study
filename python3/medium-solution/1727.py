"""
1727. Largest Submatrix With Rearrangements
    You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
    Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

    Example :
    Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
    Output: 4
    Explanation: You can rearrange the columns as shown above.
    The largest submatrix of 1s, in bold, has an area of 4.
"""

from typing import List
class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        if not matrix:
            return 0
        heights = [0] * n
        max_area = 0
        for row in matrix:
            for j in range(n):
                heights[j] = heights[j] + 1 if row[j] else 0
            sorted_h = sorted(heights, reverse = True)
            for j in range(n):
                max_area = max(max_area, sorted_h[j] * (j + 1))
        return max_area