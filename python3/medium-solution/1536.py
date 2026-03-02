"""
1536. Minimum Swaps to Arrange a Binary Grid
    Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
    A grid is said to be valid if all the cells above the main diagonal are zeros.
    Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
    The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

    Example :
    Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
    Output: 3
"""


from typing import List


class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        matrix = []
        n = len(grid) - 1
        for row in grid:
            for i in range(n, -1, -1):
                if row[i] == 1:
                    break
            matrix.append(n - i)
        swap = 0
        while matrix:
            for i, row in enumerate(matrix):
                if row >= n:
                    break
            if row < n:
                return -1
            swap += i
            matrix.pop(i)
            n -= 1
        return swap