/**
3567. Minimum Absolute Difference in Sliding Submatrix
    You are given an m x n integer matrix grid and an integer k.
    For every contiguous k x k submatrix of grid, compute the minimum absolute difference between any two distinct values within that submatrix.
    Return a 2D array ans of size (m - k + 1) x (n - k + 1), where ans[i][j] is the minimum absolute difference in the submatrix whose top-left corner is (i, j) in grid.
    Note: If all elements in the submatrix have the same value, the answer will be 0.
    A submatrix (x1, y1, x2, y2) is a matrix that is formed by choosing all cells matrix[x][y] where x1 <= x <= x2 and y1 <= y <= y2.

    Example :
    Input: grid = [[1,8],[3,-2]], k = 2
    Output: [[2]]
    Explanation:
    There is only one possible k x k submatrix: [[1, 8], [3, -2]].
    Distinct values in the submatrix are [1, 8, 3, -2].
    The minimum absolute difference in the submatrix is |1 - 3| = 2. Thus, the answer is [[2]].
 */

function minAbsDiff(grid: number[][], k: number): number[][] {
        const rows = grid.length;
    const cols = grid[0].length;

    const res: number[][] = Array.from(
        { length: rows - k + 1 },
        () => new Array(cols - k + 1).fill(0)
    );

    for (let r = 0; r <= rows - k; r++) {
        for (let c = 0; c <= cols - k; c++) {

            let window: number[] = [];

            for (let i = 0; i < k; i++)
                for (let j = 0; j < k; j++)
                    window.push(grid[r+i][c+j]);

            window.sort((a,b)=>a-b);

            let minDiff = Infinity;
            for (let i = 0; i < window.length - 1; i++) {
                const d = window[i+1] - window[i];
                if (d > 0) minDiff = Math.min(minDiff, d);
            }

            res[r][c] = minDiff === Infinity ? 0 : minDiff;
        }
    }

    return res;
};