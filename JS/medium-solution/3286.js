/**
3286. Find a Safe Walk Through a Grid
    You are given an m x n binary matrix grid and an integer health.
    You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).
    You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.
    Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.
    Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.

    Example :
    Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1
    Output: true
    Explanation:
    The final cell can be reached safely by walking along the gray cells below.
 */



/**
 * @param {number[][]} grid
 * @param {number} health
 * @return {boolean}
 */
var findSafeWalk = function(grid, health) {
    const row = grid.length;
    const col = grid[0].length;
    const dist = Array.from({ length: row }, () => Array(col).fill(-2));
    const q = [[0, 0]];
    let head = 0;
    if (grid[0][0] === 1) {

        dist[0][0] = health - 1;

        if (dist[0][0] <= 0) 
            return false;
    } else {
        dist[0][0] = health;
    }

    const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    while (head < q.length) {
        const [i, j] = q[head++];
        if (i === row - 1 && j === col - 1)
            return true;
        for (const [dx, dy] of dirs) {
            const x = i + dx;
            const y = j + dy;
            if (x >= 0 && x < row && y >= 0 && y < col && dist[x][y] === -2) {
                const cost = grid[x][y] === 1 ? 1 : 0;
                const newHealth = dist[i][j] - cost;
                if (newHealth > 0 && newHealth > dist[x][y]) {
                    dist[x][y] = newHealth;
                    if (cost === 0)
                        q.splice(head, 0, [x, y]);
                    else
                        q.push([x, y]);
                }
            }
        }
    }
    return false;
};