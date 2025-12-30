"""
840. Magic Squares In Grid
    A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
    Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?
    Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

    Example :
    Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
    Output: 1
    Explanation: 
    The following subgrid is a 3 x 3 magic square:
    while this one is not:
    In total, there is only one magic square inside the given grid.

"""


from typing import List

class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        x ,y = len(grid), len(grid[0])
        def isMagicSquares(r, c):
            s = [grid[r+i][c+j] for i in range(3) for j in range(3)]
            if sorted(s) != list(range(1,10)):
                return False
            return (s[0] + s[1] + s[2] == s[3] + s[4] + s[5] == s[6] + s[7] + s[8] == 15 and 
                    s[0] + s[3] + s[6] == s[1] + s[4] + s[7] == s[2] + s[5] + s[8] == 15 and
                    s[0] + s[4] + s[8] == s[2] + s[4] + s[6] == 15)
        count = 0
        for i in range(x-2):
            for j in range(y -2):
                if isMagicSquares(i, j):
                    count += 1
        return count