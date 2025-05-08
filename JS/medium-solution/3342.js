/**
3342. Find Minimum Time to Reach Last Room II
    There is a dungeon with n x m rooms arranged as a grid.
    You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.
    Return the minimum time to reach the room (n - 1, m - 1).
    Two rooms are adjacent if they share a common wall, either horizontally or vertically.

    Example :
    Input: moveTime = [[0,4],[4,4]]
    Output: 7
    Explanation:
    The minimum time required is 7 seconds.
    At time t == 4, move from room (0, 0) to room (1, 0) in one second.
    At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
 */

/**
 * @param {number[][]} moveTime
 * @return {number}
 */
var minTimeToReach = function(moveTime) {
    const n = moveTime.length, m = moveTime[0].length;
    const INF = Infinity;
    const dp = Array.from({ length: n }, () => Array(m).fill(INF));

    const heap = new PriorityQueue((a, b) => a.dist - b.dist);

    heap.enqueue({ x: 0, y: 0, dist: 0, move: 0 });
    moveTime[0][0] = 0; 

    const ways = [[1, 0], [0, 1], [-1, 0], [0, -1]];

    while (!heap.isEmpty()) {
        const { x, y, dist, move } = heap.dequeue();

        if (x === n - 1 && y === m - 1) {
            return dist;
        }

        for (const [dx, dy] of ways) {
            const nextRow = x + dx, nextCol = y + dy;

            if (nextRow < 0 || nextCol < 0 || nextRow >= n || nextCol >= m) {
                continue;
            }

            const count = Math.max(dist, moveTime[nextRow][nextCol]);
            const cost = (move % 2 === 0) ? 1 : 2;  
            const nextTime = count + cost;
            if (nextTime < dp[nextRow][nextCol]) {
                dp[nextRow][nextCol] = nextTime;
                heap.enqueue({ x: nextRow, y: nextCol, dist: nextTime, move: move + 1 });
            }
        }
    }

    return -1;  
};