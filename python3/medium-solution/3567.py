"""
3567. Minimum Absolute Difference in Sliding Submatrix
    You are given an m x n integer matrix grid and an integer k.
    For every contiguous k x k submatrix of grid, compute the minimum absolute difference between any two distinct values within that submatrix.
    Return a 2D array ans of size (m - k + 1) x (n - k + 1), where ans[i][j] is the minimum absolute difference in the submatrix whose top-left corner is (i, j) in grid.
    Note: If all elements in the submatrix have the same value, the answer will be 0.
    A submatrix (x1, y1, x2, y2) is a matrix that is formed by choosing all cells matrix[x][y] where x1 <= x <= x2 and y1 <= y <= y2.

    Example :
    Input: grid = [[1,8],[3,-2]], k = 2
    Output: [[2]]
    Explanation:
    There is only one possible k x k submatrix: [[1, 8], [3, -2]].
    Distinct values in the submatrix are [1, 8, 3, -2].
    The minimum absolute difference in the submatrix is |1 - 3| = 2. Thus, the answer is [[2]].
"""

            

from ast import List



class Solution:
    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
        rows = len(grid)
        cols = len(grid[0])
        res = [[0] * (cols - k + 1) for _ in range(rows - k + 1)]
        def diff(window):
            if len(window) < 2:
                return 0
            min_diff = float('inf')
            for i in range(len(window) - 1):
                diff = window[i + 1] - window[i]
                if diff > 0 and diff < min_diff:
                    min_diff = diff
            return min_diff if min_diff != float('inf') else 0
        for r in range(rows - k + 1):
            cur = []
            for i in range(k):
                for j in range(k):
                    insort(cur, grid[r+i][j])
            res[r][0] = diff(cur)
            for c in range(1, cols - k + 1):
                for i in range(k):
                    remove = grid[r+i][c-1]
                    index = bisect_left(cur, remove)
                    cur.pop(index)
                for i in range(k):
                    add = grid[r+i][c+k-1]
                    insort(cur, add)
                res[r][c] = diff(cur)
        return res
            