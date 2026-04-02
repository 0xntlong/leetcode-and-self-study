/**
3418. Maximum Amount of Money Robot Can Earn
    You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). The robot can move either right or down at any point in time.
    The grid contains a value coins[i][j] in each cell:
    If coins[i][j] >= 0, the robot gains that many coins.
    If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.
    The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them from stealing coins in those cells.
    Note: The robot's total coins can be negative.
    Return the maximum profit the robot can gain on the route.

    Example :
    Input: coins = [[0,1,-1],[1,-2,3],[2,-3,4]]
    Output: 8
    Explanation:
    An optimal path for maximum coins is:
    Start at (0, 0) with 0 coins (total coins = 0).
    Move to (0, 1), gaining 1 coin (total coins = 0 + 1 = 1).
    Move to (1, 1), where there's a robber stealing 2 coins. The robot uses one neutralization here, avoiding the robbery (total coins = 1).
    Move to (1, 2), gaining 3 coins (total coins = 1 + 3 = 4).
    Move to (2, 2), gaining 4 coins (total coins = 4 + 4 = 8).
 */



function maximumAmount(coins: number[][]): number {
    const m: number = coins.length;
    const n: number = coins[0].length;
    const INF: number = Number.MAX_SAFE_INTEGER;
    let dp: number[][] = Array.from({ length: n + 1 }, () => Array(3).fill(-INF));

    for (let k = 0; k < 3; k++) {
        dp[1][k] = 0;
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const x: number = coins[i][j];
            const col: number = j + 1;
            const next2: number = Math.max(dp[col - 1][2] + x, dp[col][2] + x, 
                                           dp[col - 1][1], dp[col][1]);
            const next1: number = Math.max(dp[col - 1][1] + x, dp[col][1] + x, 
                                           dp[col - 1][0], dp[col][0]);
            const next0: number = Math.max(dp[col - 1][0], dp[col][0]) + x;

            dp[col][2] = next2;
            dp[col][1] = next1;
            dp[col][0] = next0;
        }
    }

    return dp[n][2];
};