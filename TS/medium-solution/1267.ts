/*
1267. Count Servers that Communicate
    You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.
    Return the number of servers that communicate with any other server.
    Example :
    Input: grid = [[1,0],[0,1]]
    Output: 0
    Explanation: No servers can communicate with others.
*/



function countServers(grid: number[][]): number {
    const m = grid.length, n = grid[0].length;

    const row: number[] = new Array(m).fill(0);
    const col: number[] = new Array(n).fill(0);

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                row[i]++;
                col[j]++;
            }
        }
    }

    let count = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                if (row[i] > 1 || col[j] > 1) {
                    count++;
                }
            }
        }
    }

    return count;
};