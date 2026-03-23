/**
1594. Maximum Non Negative Product in a Matrix
    You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.
    Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.
    Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.
    Notice that the modulo is performed after getting the maximum product.
    Example :
    Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
    Output: -1
    Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
 */


/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxProductPath = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    const MOD = 1e9 + 7;

    const Min = Array.from({ length: m }, () => Array(n).fill(Infinity));
    const Max = Array.from({ length: m }, () => Array(n).fill(-Infinity));

    Min[0][0] = Max[0][0] = grid[0][0];

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 && j === 0) 
                continue;

            let mn = Infinity;
            let mx = -Infinity;

            if (i > 0) {
                const a = Min[i-1][j] * grid[i][j];
                const b = Max[i-1][j] * grid[i][j];
                mn = Math.min(mn, a, b);
                mx = Math.max(mx, a, b);
            }

            if (j > 0) {
                const a = Min[i][j-1] * grid[i][j];
                const b = Max[i][j-1] * grid[i][j];
                mn = Math.min(mn, a, b);
                mx = Math.max(mx, a, b);
            }

            Min[i][j] = mn;
            Max[i][j] = mx;
        }
    }

    const res = Max[m-1][n-1];
    return res >= 0 ? res % MOD : -1;
};