/**
1914. Cyclically Rotating a Grid
    You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.
    The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:
    A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:
    Return the matrix after applying k cyclic rotations to it.

    Example :
    Input: grid = [[40,10],[30,20]], k = 1
    Output: [[10,20],[40,30]]
    Explanation: The figures above represent the grid at every state.
 */


/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */
var rotateGrid = function(grid, k) {
    const m = grid.length;
    const n = grid[0].length;

    for (let layer = 0; layer < Math.min(m, n) / 2; layer++) {
        const r = [];
        const c = [];
        const val = [];

        for (let i = layer; i < m - layer - 1; i++) {
            r.push(i);
            c.push(layer);
            val.push(grid[i][layer]);
        }

        for (let j = layer; j < n - layer -1; j++) {
            r.push(m - layer - 1);
            c.push(j);
            val.push(grid[m - layer - 1][j]);
        }

        for (let i = m - layer - 1; i > layer; i--) {
            r.push(i);
            c.push(n - layer - 1);
            val.push(grid[i][n - layer - 1]);
        }

        for (let j = n - layer - 1; j > layer; j--) {
            r.push(layer);
            c.push(j);
            val.push(grid[layer][j]);
        }
        const total = val.length;
        const kk = k % total;

        for (let i = 0; i < total; i++) {
            const idx = (i + total - kk) % total;
            grid[r[i]][c[i]] = val[idx];
        }
    }
    return grid;
};