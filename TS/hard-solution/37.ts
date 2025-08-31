/**
37. Sudoku Solver
    Write a program to solve a Sudoku puzzle by filling the empty cells.

    A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
    The '.' character indicates empty cells.

    

    Example 1:


    Input: board = [["5","3",".",".","7",".",".",".","."],
                    ["6",".",".","1","9","5",".",".","."],
                    [".","9","8",".",".",".",".","6","."],
                    ["8",".",".",".","6",".",".",".","3"],
                    ["4",".",".","8",".","3",".",".","1"],
                    ["7",".",".",".","2",".",".",".","6"],
                    [".","6",".",".",".",".","2","8","."],
                    [".",".",".","4","1","9",".",".","5"],
                    [".",".",".",".","8",".",".","7","9"]]

    Output:         [["5","3","4","6","7","8","9","1","2"],
                    ["6","7","2","1","9","5","3","4","8"],
                    ["1","9","8","3","4","2","5","6","7"],
                    ["8","5","9","7","6","1","4","2","3"],
                    ["4","2","6","8","5","3","7","9","1"],
                    ["7","1","3","9","2","4","8","5","6"],
                    ["9","6","1","5","3","7","2","8","4"],
                    ["2","8","7","4","1","9","6","3","5"],
                    ["3","4","5","2","8","6","1","7","9"]]
 */


/**
 Do not return anything, modify board in-place instead.
 */
function solveSudoku(board: string[][]): void {
    const N = 9, BOX = 3;
    let solved = false;
    const rows: number[][] = Array.from({ length: N }, () => Array(10).fill(0));
    const cols: number[][] = Array.from({ length: N }, () => Array(10).fill(0));
    const boxes: number[][] = Array.from({ length: N }, () => Array(10).fill(0));

    const boxId = (r: number, c: number): number =>
        Math.floor(r / BOX) * BOX + Math.floor(c / BOX);

    const canPlace = (d: number, r: number, c: number): boolean => {
        const b = boxId(r, c);
        return rows[r][d] === 0 && cols[c][d] === 0 && boxes[b][d] === 0;
    };

    const place = (d: number, r: number, c: number): void => {
        const b = boxId(r, c);
        rows[r][d]++; cols[c][d]++; boxes[b][d]++;
        board[r][c] = String(d);
    };

    const remove = (d: number, r: number, c: number): void => {
        const b = boxId(r, c);
        rows[r][d]--; cols[c][d]--; boxes[b][d]--;
        board[r][c] = '.';
    };

    const advance = (r: number, c: number): void => {
        if (r === N - 1 && c === N - 1) {
            solved = true;
        } else if (c === N - 1) {
            backtrack(r + 1, 0);
        } else {
            backtrack(r, c + 1);
        }
    };

    const backtrack = (r: number, c: number): void => {
        if (board[r][c] === '.') {
            for (let d = 1; d <= 9 && !solved; d++) {
                if (canPlace(d, r, c)) {
                    place(d, r, c);
                    advance(r, c);
                    if (!solved) remove(d, r, c);
                }
            }
        } else {
            advance(r, c);
        }
    };
    
    for (let r = 0; r < N; r++) {
        for (let c = 0; c < N; c++) {
            if (board[r][c] !== '.') {
                place(parseInt(board[r][c], 10), r, c);
            }
        }
    }
    backtrack(0, 0);
};