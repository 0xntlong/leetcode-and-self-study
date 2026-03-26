"""
3548. Equal Sum Grid Partition II

    You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

    Each of the two resulting sections formed by the cut is non-empty.
    The sum of elements in both sections is equal, or can be made equal by discounting at most one single cell in total (from either section).
    If a cell is discounted, the rest of the section must remain connected.
    Return true if such a partition exists; otherwise, return false.

    Note: A section is connected if every cell in it can be reached from any other cell by moving up, down, left, or right through other cells in the section.

    Example :
    Input: grid = [[1,4],[2,3]]
    Output: true
    Explanation:



    A horizontal cut after the first row gives sums 1 + 4 = 5 and 2 + 3 = 5, which are equal. Thus, the answer is true.
"""

from typing import List

class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        total = 0
        rows = len(grid)
        cols = len(grid[0])
        for i in range(rows):
            for j in range(cols):
                total += grid[i][j]
        for _ in range(4):
            visited = set()
            visited.add(0)
            vals = 0
            rows = len(grid)
            cols = len(grid[0])
            if rows < 2:
                grid = self.rotation(grid)
                continue
            if cols == 1:
                for i in range(rows - 1):
                    vals += grid[i][0]
                    flag = vals * 2 - total
                    if flag == 0 or flag == grid[0][0] or flag == grid[i][0]:
                        return True
                grid = self.rotation(grid)
                continue
            for i in range(rows - 1):
                for j in range(cols):
                    visited.add(grid[i][j])
                    vals += grid[i][j]
                flag = vals * 2 - total
                if i == 0:
                    if flag == 0 or flag == grid[0][0] or flag == grid[i][cols - 1]:
                        return True
                    continue
                if flag in visited:
                    return True
            grid = self.rotation(grid)
        return False
        
    def rotation(self, grid: List[List[int]]) -> List[List[int]]:
        rows = len(grid)
        cols = len(grid[0])
        tmp = [[0] * rows for _ in range(cols)]
        for i in range(rows):
            for j in range(cols):
                tmp[j][rows - 1 - i] = grid[i][j]
        return tmp