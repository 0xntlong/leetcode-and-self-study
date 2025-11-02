/*
2257. Count Unguarded Cells in the Grid
    You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
    A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.
    Return the number of unoccupied cells that are not guarded.

    Example :
    Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
    Output: 7
    Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
    There are a total of 7 unguarded cells, so we return 7.

*/




function countUnguarded(m: number, n: number, guards: number[][], walls: number[][]): number {
    const grid: number[][] = Array.from({ length: m }, () => Array(n).fill(0));

    for (const [r, c] of walls)
        grid[r][c] = 1;
    for (const [r, c] of guards)
        grid[r][c] = 1;

    for (const [r, c] of guards) {
        for (let i = r - 1; i >= 0 && grid[i][c] !== 1; i--) 
            grid[i][c] = 2;
        for (let i = r + 1; i < m && grid[i][c] !== 1; i++) 
            grid[i][c] = 2;
        for (let j = c - 1; j >= 0 && grid[r][j] !== 1; j--)
            grid[r][j] = 2;
        for (let j = c + 1; j < n && grid[r][j] !== 1; j++) 
            grid[r][j] = 2;
    }

    let unguarded = 0;
    for (let i = 0; i < m; i++)
        for (let j = 0; j < n; j++)
            if (grid[i][j] === 0)
                unguarded++;

    return unguarded;
};