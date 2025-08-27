"""
3459. Length of Longest V-Shaped Diagonal Segment
    You are given a 2D integer matrix grid of size n x m, where each element is either 0, 1, or 2.
    A V-shaped diagonal segment is defined as:
    The segment starts with 1.
    The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
    The segment:
    Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
    Continues the sequence in the same diagonal direction.
    Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.

    Return the length of the longest V-shaped diagonal segment. If no valid segment exists, return 0.

    Example :
    Input: grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
    Output: 5
    Explanation:
    The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,2) → (1,3) → (2,4), takes a 90-degree clockwise turn at (2,4), and continues as (3,3) → (4,2).
"""



from typing import List
import functools

class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        ways = [(1, 1), (1, -1), (-1, -1), (-1, 1)]
        n = len(grid)
        m = len(grid[0])
        new_val = [2, 2, 0]
        @functools.cache
        def dp(x, y, t, w):
            res = 1
            dx, dy = ways[w]
            if 0 <= x + dx < n and 0 <= y + dy < m and grid[x + dx][y + dy] == new_val[grid[x][y]]:
                res = dp(x + ways[w][0], y + ways[w][1], t, w) + 1
            if not t:
                dx, dy = ways[(w + 1) % 4]
                if 0 <= x + dx < n and 0 <= y + dy < m and grid[x + dx][y + dy] == new_val[grid[x][y]]:
                    res = max(res, dp(x + dx, y + dy, True, (w + 1) % 4) + 1)

            return res
        total = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    tm = (n - i, j + 1, i + 1, m - j)
                    for d in range(4):
                        if tm[d] > total:
                            total = max(total, dp(i, j, False, d))
        return total
