/**
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
 */



/**
 * @param {number[][]} grid
 * @return {number}
 */
var numMagicSquaresInside = function(grid) {
    const x = grid.length;
    const y = grid[0].length;
    let count = 0;

    const isMagic = (r, c) => {
        const s = [];
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                s.push(grid[r + i][c + j]);
            }
        }

        const seen = Array(10).fill(false);
        for (const v of s) {
            if (v < 1 || v > 9 || seen[v]) return false;
            seen[v] = true;
        }

        return s[0] + s[1] + s[2] === 15 &&
               s[3] + s[4] + s[5] === 15 &&
               s[6] + s[7] + s[8] === 15 &&
               s[0] + s[3] + s[6] === 15 &&
               s[1] + s[4] + s[7] === 15 &&
               s[2] + s[5] + s[8] === 15 &&
               s[0] + s[4] + s[8] === 15 &&
               s[2] + s[4] + s[6] === 15;
    };

    for (let i = 0; i <= x - 3; i++) {
        for (let j = 0; j <= y - 3; j++) {
            if (isMagic(i, j)) count++;
        }
    }

    return count;
};