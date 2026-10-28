/**
3882. Minimum XOR Path in a Grid
    You are given a 2D integer array grid of size m * n.
    You start at the top-left cell (0, 0) and want to reach the bottom-right cell (m - 1, n - 1).
    At each step, you may move either right or down.
    The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, including the start and end cells.
    Return the minimum possible XOR value among all valid paths from (0, 0) to (m - 1, n - 1).

    Example :
    Input: grid = [[1,2],[3,4]]
    Output: 6
    Explanation:
    There are two valid paths:
    (0, 0) → (0, 1) → (1, 1) with XOR: 1 XOR 2 XOR 4 = 7
    (0, 0) → (1, 0) → (1, 1) with XOR: 1 XOR 3 XOR 4 = 6
    The minimum XOR value among all valid paths is 6.
 */



function minCost(grid: number[][]): number {
    const m: number = grid.length;
    const n: number = grid[0].length;

    const dp: Set<number>[] = Array.from(
        { length: n },
        () => new Set<number>()
    );

    dp[0].add(grid[0][0]);

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 && j === 0) {
                continue;
            }

            const value: number = grid[i][j];
            const reachable: Set<number> = new Set(dp[j]);

            if (j > 0) {
                for (const k of dp[j - 1]) {
                    reachable.add(k);
                }
            }

            dp[j] = new Set<number>(
                [...reachable].map(k => k ^ value)
            );
        }
    }

    return Math.min(...dp[n - 1]);
};