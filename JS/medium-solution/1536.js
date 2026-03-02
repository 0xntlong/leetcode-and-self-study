/**
1536. Minimum Swaps to Arrange a Binary Grid
    Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
    A grid is said to be valid if all the cells above the main diagonal are zeros.
    Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
    The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

    Example :
    Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
    Output: 3
 */



/**
 * @param {number[][]} grid
 * @return {number}
 */
var minSwaps = function(grid) {
    let matrix = [];
    let n = grid.length - 1;

    for (const row of grid) {
        let i;
        for (i = n; i >= 0; i--) {
            if (row[i] === 1) 
                break;
        }
        matrix.push(n - i);
    }

    let swap = 0;
    while (matrix.length > 0) {
        let i, row = 0;
        for (i = 0; i < matrix.length; i++) {
            row = matrix[i];
            if (row >= n) 
                break;
        }
        if (row < n) 
            return -1;

        swap += i;
        matrix.splice(i, 1);
        n -= 1;
    }
    return swap;
};