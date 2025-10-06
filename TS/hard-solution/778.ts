/**
778. Swim in Rising Water
    You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
    It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.
    You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
    Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

    Example :
    Input: grid = [[0,2],[1,3]]
    Output: 3
    Explanation:
    At time 0, you are in grid location (0, 0).
    You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
    You cannot reach point (1, 1) until time 3.
    When the depth of water is 3, we can swim anywhere inside the grid.
 */


function swimInWater(grid: number[][]): number {
    const n = grid.length;
    const dirs: number[][] = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    function canReach(t: number): boolean {
        const visited: boolean[][] = Array.from({ length: n }, () => Array(n).fill(false));
        
        function dfs(x: number, y: number): boolean {
            if (x === n - 1 && y === n - 1) return true; 
            visited[x][y] = true;

            for (const [dx, dy] of dirs) {
                const nx = x + dx, ny = y + dy;
                if (
                    nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    !visited[nx][ny] && grid[nx][ny] <= t
                ) {
                    if (dfs(nx, ny)) return true;
                }
            }
            return false;
        }
        return grid[0][0] <= t && dfs(0, 0); 
    }
    let left = Math.max(grid[0][0], grid[n - 1][n - 1]);
    let right = n * n - 1;

    while (left < right) {
        const mid = Math.floor((left + right) / 2);
        if (canReach(mid)) right = mid;
        else left = mid + 1;
    }

    return left;
};