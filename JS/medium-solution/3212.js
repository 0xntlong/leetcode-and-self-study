/**
3212. Count Submatrices With Equal Frequency of X and Y
    Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
    grid[0][0]
    an equal frequency of 'X' and 'Y'.
    at least one 'X'.

    Example :

    Input: grid = [["X","Y","."],["Y",".","."]]

    Output: 3
 */



/**
 * @param {character[][]} grid
 * @return {number}
 */
var numberOfSubmatrices = function(grid) {
    const m = grid.length;
    const n = grid[0].length;

    const ox = new Array(n).fill(0);
    const oy = new Array(n).fill(0);

    let res = 0;

    for (let i = 0; i < m; i++) {
        let rowX = 0;
        let rowY = 0;

        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 'X')
                rowX++;
            else if (grid[i][j] === 'Y')
                rowY++;

            ox[j] += rowX;
            oy[j] += rowY;

            if (ox[j] === oy[j] && ox[j] > 0)
                res++;
        }
    }

    return res;
};