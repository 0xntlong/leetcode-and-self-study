"""
1351. Count Negative Numbers in a Sorted Matrix
    Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

    Example:
    Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    Output: 8
    Explanation: There are 8 negatives number in the matrix.
"""
from typing import List 
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        def matrix(row):
            x, y = 0, len(row)
            while x < y:
                mid = x + (y - x) // 2
                if row[mid] < 0:
                    y = mid
                else:
                    x = mid + 1
            return len(row) - x
        count = 0
        for row in grid:
            count += matrix(row)
        return (count)