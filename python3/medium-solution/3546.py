"""
3546. Equal Sum Grid Partition I
    You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:
    Each of the two resulting sections formed by the cut is non-empty.
    The sum of the elements in both sections is equal.
    Return true if such a partition exists; otherwise return false.

    Example :
    Input: grid = [[1,4],[2,3]]

    Output: true
    Explanation:
    A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.
"""


from typing import List
class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        rows = len(grid)
        cols = len(grid[0])
        total = sum(sum(row) for row in grid)
        if total % 2 != 0:
            return False
        target = total // 2
        colSum = 0
        for i in range(cols - 1):
            for j in range(rows):
                colSum += grid[j][i]
            if colSum == target:
                return True
        rowSum = 0
        for j in range(rows - 1):
            for i in range(cols):
                rowSum += grid[j][i]
            if rowSum == target:
                return True
        return False