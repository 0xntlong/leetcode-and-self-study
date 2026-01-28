/**
3651. Minimum Cost Path with Teleportations
    You are given a m x n 2D integer array grid and an integer k. You start at the top-left cell (0, 0) and your goal is to reach the bottom‐right cell (m - 1, n - 1).
    There are two types of moves available:
    Normal move: You can move right or down from your current cell (i, j), i.e. you can move to (i, j + 1) (right) or (i + 1, j) (down). The cost is the value of the destination cell.
    Teleportation: You can teleport from any cell (i, j), to any cell (x, y) such that grid[x][y] <= grid[i][j]; the cost of this move is 0. You may teleport at most k times.
    Return the minimum total cost to reach cell (m - 1, n - 1) from (0, 0).
    Example :
    Input: grid = [[1,3,3],[2,5,4],[4,3,5]], k = 2
    Output: 7
    Explanation:
    Initially we are at (0, 0) and cost is 0.
    Current Position	Move	New Position	Total Cost
    (0, 0)	Move Down	(1, 0)	0 + 2 = 2
    (1, 0)	Move Right	(1, 1)	2 + 5 = 7
    (1, 1)	Teleport to (2, 2)	(2, 2)	7 + 0 = 7
    The minimum cost to reach bottom-right cell is 7.
 */ 


/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var minCost = function(grid, k) {
    const m = grid.length;
    const n = grid[0].length;
    const INF = 1e30;
    const total = m * n;
    const cells = [];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const idx = i * n + j;
            cells.push([grid[i][j], idx]);
        }
    }
    cells.sort((a, b) => (b[0] - a[0]) || (b[1] - a[1])); 
    let dist = new Array(total).fill(INF);
    dist[0] = 0;
    let best = INF;
    for (let t = 0; t <= k; t++) {
        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                const idx = i * n + j;
                const cur = dist[idx];
                if (cur >= INF) 
                    continue;

                if (j + 1 < n) {
                    const ni = idx + 1;
                    const cost = cur + grid[i][j + 1];
                    if (cost < dist[ni]) 
                        dist[ni] = cost;
                }
                if (i + 1 < m) {
                    const ni = idx + n;
                    const cost = cur + grid[i + 1][j];
                    if (cost < dist[ni]) 
                        dist[ni] = cost;
                }
            }
        }

        best = Math.min(best, dist[total - 1]);
        if (t === k) 
            break;
        const nextDist = new Array(total).fill(INF);
        let move = INF;
        let p = 0;
        while (p < cells.length) {
            const val = cells[p][0];
            let q = p;
            let groupMin = INF;
            while (q < cells.length && cells[q][0] === val) {
                groupMin = Math.min(groupMin, dist[cells[q][1]]);
                q++;
            }
            move = Math.min(move, groupMin);
            for (let t2 = p; t2 < q; t2++) {
                const idx = cells[t2][1];
                nextDist[idx] = move;
            }
            p = q;
        }
        dist = nextDist;
    }
    return best >= INF ? -1 : best;
};