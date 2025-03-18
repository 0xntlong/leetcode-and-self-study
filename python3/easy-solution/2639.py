"""
2639. Find the Width of the Columns in a Grid
    You are given a 0-indexed m x n integer matrix grid. The width of a column is the maximum length of its integers.
    For example, if grid = [[-10], [3], [12]], the width of the only column is 3 since -10 is of length 3.
    Return an integer array ans of size n where ans[i] is the width of the ith column.
    The length of an integer x with len digits is equal to len if x is non-negative, and len + 1 otherwise.

    Example :
    Input: grid = [[1],[22],[333]]
    Output: [3]
    Explanation: In the 0th column, 333 is of length 3.
"""

from typing import List
class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        col = len(grid[0])
        res = []
        for i in range(col):
            temp = []
            for row in grid:
                temp.append(len(str(row[i])))
            res.append(max(temp))
        return res