"""
3446. Sort Matrix by Diagonals
    You are given an n x n square matrix of integers grid. Return the matrix such that:
    The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
    The diagonals in the top-right triangle are sorted in non-decreasing order.

    Example :
    Input: grid = [[1,7,3],[9,8,2],[4,5,6]]
    Output: [[8,2,3],[9,6,7],[4,5,1]]
    Explanation:
    The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:
    [1, 8, 6] becomes [8, 6, 1].
    [9, 5] and [4] remain unchanged.
    The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:
    [7, 2] becomes [2, 7].
    [3] remains unchanged.
"""



from types import List
class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        for k in range(n):
            arr = []
            i, j = k, 0
            while i < n:
                arr.append(grid[i][j])
                i += 1
                j += 1
            arr.sort(reverse=True)
            i, j = k, 0
            while i < n:
                grid[i][j] = arr[j]
                i += 1
                j += 1
        for k in range(1, n):
            arr = []
            i, j = 0, k
            while j < n:
                arr.append(grid[i][j])
                i += 1
                j += 1
            arr.sort()
            i, j = 0, k
            while j < n:
                grid[i][j] = arr[i]
                i += 1
                j += 1
        return grid