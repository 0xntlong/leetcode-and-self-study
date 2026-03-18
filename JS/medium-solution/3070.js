/**
3070. Count Submatrices with Top-Left Element and Sum Less Than k
    You are given a 0-indexed integer matrix grid and an integer k.re4ắ32
    Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.
    Example :
    Input: grid = [[7,6,3],[6,6,1]], k = 18
    Output: 4
    Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.

 */



/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var countSubmatrices = function(grid, k) {
    const r = grid.length;
    const c = grid[0].length;

    const cols = new Array(c).fill(0);
    let res = 0;

    for (let i = 0; i < r; i++) {
        let rowSum = 0;
        for (let j = 0; j < c; j++) {
            cols[j] += grid[i][j];
            rowSum += cols[j];
            if (rowSum <= k)
                res++;
        }
    }

    return res;
};