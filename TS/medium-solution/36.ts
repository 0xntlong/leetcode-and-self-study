/**
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
 */



function isValidSudoku(board: string[][]): boolean {
    const rows: Set<string>[] = Array.from({length: 9}, () => new Set());
    const cols: Set<string>[] = Array.from({length: 9}, () => new Set());
    const boxes: Set<string>[] = Array.from({length: 9}, () => new Set());

    for (let r = 0; r < 9; r++){
        for (let c = 0; c < 9; c++){
            const val = board[r][c];
            if (val === '.')
                continue;
            const b = Math.floor(r / 3) * 3 + Math.floor(c / 3);
            if (rows[r].has(val) || cols[c].has(val) || boxes[b].has(val)){
                return false;
            }
            rows[r].add(val);
            cols[c].add(val);
            boxes[b].add(val);
        }
    }
    return true;
};