/**
1260. Shift 2D Grid
    Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.
    In one shift operation:
    Element at grid[i][j] moves to grid[i][j + 1].
    Element at grid[i][n - 1] moves to grid[i + 1][0].
    Element at grid[m - 1][n - 1] moves to grid[0][0].
    Return the 2D grid after applying shift operation k times.

    Example :
    Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
    Output: [[9,1,2],[3,4,5],[6,7,8]]
 */


function shiftGrid(grid: number[][], k: number): number[][] {
    const n = grid.length;
    const m = grid[0].length;

    const res: number[][] = Array.from(
        { length: n },
        () => Array(m).fill(0)
    );

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            const newJ = (j + k) % m;
            const newI = (i + Math.floor((j + k) / m)) % n;

            res[newI][newJ] = grid[i][j];
        }
    }

    return res;
}