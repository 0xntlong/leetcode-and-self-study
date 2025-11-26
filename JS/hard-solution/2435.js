/**
2435. Paths in Matrix Whose Sum Is Divisible by K
    You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.
    Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 109 + 7.

    Example :
    Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
    Output: 2
    Explanation: There are two paths where the sum of the elements on the path is divisible by k.
    The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
    The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.
 */



/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var numberOfPaths = function(grid, k) {
    const m = grid.length, n = grid[0].length;
    const mod = 1000000007;
    let dp = Array.from({ length: m }, () => Array.from({ length: n }, () => Array(k).fill(0)));
    dp[0][0][grid[0][0] % k] = 1;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let x = 0; x < k; x++) {
                let new_mod = (x + grid[i][j]) % k;
                if (i == 0 && j > 0) {
                    dp[i][j][new_mod] += dp[i][j - 1][x];
                }
                if (j == 0 && i > 0) {
                    dp[i][j][new_mod] += dp[i - 1][j][x];
                }
                if (i > 0 && j > 0) {
                    dp[i][j][new_mod] += dp[i - 1][j][x] + dp[i][j - 1][x];
                }
                dp[i][j][new_mod] %= mod;
            }
        }
    }

    return dp[m - 1][n - 1][0];
};