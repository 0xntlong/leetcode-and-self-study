"""
3070. Count Submatrices with Top-Left Element and Sum Less Than k
    You are given a 0-indexed integer matrix grid and an integer k.re4ắ32
    Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.
    Example :
    Input: grid = [[7,6,3],[6,6,1]], k = 18
    Output: 4
    Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.
"""


from typing import List
class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        r = len(grid)
        c = len(grid[0])
        cols = [0] * c
        res = 0
        for i in range(r):
            row_sum = 0
            for j in range(c):
                cols[j] += grid[i][j]
                row_sum += cols[j]
                if row_sum <= k:
                    res += 1
        return res