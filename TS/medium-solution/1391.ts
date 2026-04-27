/**
1391. Check if There is a Valid Path in a Grid
    You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:
    1 which means a street connecting the left cell and the right cell.
    2 which means a street connecting the upper cell and the lower cell.
    3 which means a street connecting the left cell and the lower cell.
    4 which means a street connecting the right cell and the lower cell.
    5 which means a street connecting the left cell and the upper cell.
    6 which means a street connecting the right cell and the upper cell.
    You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.
    Notice that you are not allowed to change any street.
    Return true if there is a valid path in the grid or false otherwise.

    Example :
    Input: grid = [[2,4,3],[6,5,2]]
    Output: true
    Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
 */


function hasValidPath(grid: number[][]): boolean {
    const rows = grid.length, cols = grid[0].length;

    const dirs: Record<number, Set<number>> = {
        1: new Set([0, 1]), 
        2: new Set([2, 3]), 
        3: new Set([0, 3]),
        4: new Set([1, 3]), 
        5: new Set([0, 2]), 
        6: new Set([1, 2])
    };

    const moves = [
        [0, -1, 0, 1], 
        [0, 1, 1, 0], 
        [-1, 0, 2, 3], 
        [1, 0, 3, 2]
    ];
                    
    const visited = Array.from({ length: rows }, () => Array(cols).fill(false));
    
    const queue = [[0, 0]];
    visited[0][0] = true;

    while (queue.length > 0) {
        const [r, c] = queue.shift()!;
        if (r === rows - 1 && c === cols - 1) 
            return true;

        for (const [dr, dc, outD, inD] of moves) {
            const nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                if (dirs[grid[r][c]].has(outD) && dirs[grid[nr][nc]].has(inD)) {
                    visited[nr][nc] = true;
                    queue.push([nr, nc]);
                }
            }
        }
    }
    return false;
};