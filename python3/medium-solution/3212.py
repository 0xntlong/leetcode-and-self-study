"""
3212. Count Submatrices With Equal Frequency of X and Y
    Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
    grid[0][0]
    an equal frequency of 'X' and 'Y'.
    at least one 'X'.

    Example :

    Input: grid = [["X","Y","."],["Y",".","."]]

    Output: 3

"""

from typing import List
class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        res = 0
        ox = [0] * n
        oy = [0] * n
        for i in range(m):
            rowx, rowy = 0, 0
            for j in range(n):
                if grid[i][j] == 'X':
                    rowx += 1
                elif grid[i][j] == 'Y':
                    rowy += 1
                ox[j] += rowx
                oy[j] += rowy
                if ox[j] == oy[j] and ox[j] > 0:
                    res += 1
        return res