/**
1931. Painting a Grid With Three Different Colors
    You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
    Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.Example :
    
    nput: m = 1, n = 1
    Output: 3
    Explanation: The three possible colorings are shown in the image above.
 */


/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var colorTheGrid = function(m, n) {
    const mod = 1e9 + 7;
    const state = [];
    const matrix = [];
    function DFS(pos, prevColor, mask){
        if (pos === m){
            state.push(mask);
            return;
        }
        for (let color = 0; color < 3; color++){
            if (color !== prevColor){
                DFS(pos + 1, color, mask * 3 + color);
            }
        }
    }
    function valid(a, b){
        for (let i = 0; i < m; i++){
            if ((a % 3) === (b % 3))
                return false;
            a = Math.floor(a / 3);
            b = Math.floor(b / 3);
        }
        return true;
    }
    DFS(0, -1, 0);
    const s = state.length;
    for (let i = 0; i < s; i++){
        matrix.push([]);
        for (let j = 0; j < s; j++){
            if (valid(state[i], state[j])){
                matrix[i].push(j);
            }
        }
    }
    let dp = new Array(s).fill(1);
    for (let col = 1; col < n; col++){
        const new_dp = new Array(s).fill(0);
        for (let i = 0; i < s; i++){
            for (let j of matrix[i]){
                new_dp[j] = (new_dp[j] + dp[i]) % mod;
            }
        }
        dp = new_dp;
    }
    return dp.reduce((a, b) => (a + b) % mod, 0);
};