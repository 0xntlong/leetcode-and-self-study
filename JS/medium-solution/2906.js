/**
2906. Construct Product Matrix
    Given a 0-indexed 2D integer matrix grid of size n * m, we define a 0-indexed 2D matrix p of size n * m as the product matrix of grid if the following condition is met:
    Each element p[i][j] is calculated as the product of all elements in grid except for the element grid[i][j]. This product is then taken modulo 12345.
    Return the product matrix of grid.

    Example :
    Input: grid = [[1,2],[3,4]]
    Output: [[24,12],[8,6]]
    Explanation: p[0][0] = grid[0][1] * grid[1][0] * grid[1][1] = 2 * 3 * 4 = 24
    p[0][1] = grid[0][0] * grid[1][0] * grid[1][1] = 1 * 3 * 4 = 12
    p[1][0] = grid[0][0] * grid[0][1] * grid[1][1] = 1 * 2 * 4 = 8
    p[1][1] = grid[0][0] * grid[0][1] * grid[1][0] = 1 * 2 * 3 = 6
    So the answer is [[24,12],[8,6]].
 */



/**
 * @param {number[][]} grid
 * @return {number[][]}
 */
var constructProductMatrix = function(grid) {
    const n = grid.length;
    const m = grid[0].length;
    const MOD = 12345;

    const dp = Array.from({ length: n }, () => Array(m).fill(0));

    let total = 1;
    for (let i = n - 1; i >= 0; i--) {
        for (let j = m - 1; j >= 0; j--) {
            dp[i][j] = total;
            total = (total * grid[i][j]) % MOD;
        }
    }

    total = 1;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            dp[i][j] = (dp[i][j] * total) % MOD;
            total = (total * grid[i][j]) % MOD;
        }
    }

    return dp;
};