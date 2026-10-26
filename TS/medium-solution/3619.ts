/**
3619. Count Islands With Total Value Divisible by K
    You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally or vertically).
    The total value of an island is the sum of the values of all cells in the island.
    Return the number of islands with a total value divisible by k.

    Example :
    Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5
    Output: 2
    Explanation:
    The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.
 */



function countIslands(grid: number[][], k: number): number {
    const m = grid.length;
    const n = grid[0].length;
    const directions = [1, 0, -1, 0, 1];
    const queue: number[] = new Array(m * n);
    let count = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 0) continue;

            let head = 0;
            let tail = 0;
            queue[tail++] = i * n + j;

            let total = grid[i][j];
            grid[i][j] = 0;

            while (head < tail) {
                const cell = queue[head++];
                const r = Math.floor(cell / n);
                const c = cell % n;

                for (let d = 0; d < 4; d++) {
                    const nr = r + directions[d];
                    const nc = c + directions[d + 1];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                        grid[nr][nc] === 0) {
                        continue;
                    }

                    total += grid[nr][nc];
                    grid[nr][nc] = 0;
                    queue[tail++] = nr * n + nc;
                }
            }

            if (total % k === 0) count++;
        }
    }

    return count;
};