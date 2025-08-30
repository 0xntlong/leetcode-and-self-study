"""
36. Valid Sudoku
    Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
    Note:
    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.
    
    Example :
    Input: board = 
    [["5","3",".",".","7",".",".",".","."]
    ,["6",".",".","1","9","5",".",".","."]
    ,[".","9","8",".",".",".",".","6","."]
    ,["8",".",".",".","6",".",".",".","3"]
    ,["4",".",".","8",".","3",".",".","1"]
    ,["7",".",".",".","2",".",".",".","6"]
    ,[".","6",".",".",".",".","2","8","."]
    ,[".",".",".","4","1","9",".",".","5"]
    ,[".",".",".",".","8",".",".","7","9"]]
    Output: true
"""


from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_set = set()
        col_set = set()
        for r, row in enumerate(board):
            for c, val in enumerate(row):
                if val != '.':
                    if (((r, val) in row_set) or ((c, val) in col_set) or ((r // 3, c // 3, val) in col_set)):
                        return False
                    else:
                        row_set.add((r, val))
                        col_set.add((c, val))
                        col_set.add((r // 3, c // 3, val))
        return True