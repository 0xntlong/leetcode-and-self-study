/**
3661. Maximum Walls Destroyed by Robots
    There is an endless straight line populated with some robots and walls. You are given integer arrays robots, distance, and walls:
    robots[i] is the position of the ith robot.
    distance[i] is the maximum distance the ith robot's bullet can travel.
    walls[j] is the position of the jth wall.
    Every robot has one bullet that can either fire to the left or the right at most distance[i] meters.
    A bullet destroys every wall in its path that lies within its range. Robots are fixed obstacles: if a bullet hits another robot before reaching a wall, it immediately stops at that robot and cannot continue.
    Return the maximum number of unique walls that can be destroyed by the robots.
    Notes:
    A wall and a robot may share the same position; the wall can be destroyed by the robot at that position.
    Robots are not destroyed by bullets.
    Example :
    Input: robots = [4], distance = [3], walls = [1,10]
    Output: 1
    Explanation:

    robots[0] = 4 fires left with distance[0] = 3, covering [1, 4] and destroys walls[0] = 1.
    Thus, the answer is 1.
 */


/**
 * @param {number[]} robots
 * @param {number[]} distance
 * @param {number[]} walls
 * @return {number}
 */
var maxWalls = function(robots, distance, walls) {
    const n = robots.length;
    if (n === 0) 
        return 0;

    walls.sort((a, b) => a - b);

    const rData = robots.map((pos, i) => ({
        pos: pos,
        dist: distance[i]
    })).sort((a, b) => a.pos - b.pos);

    const lowerBound = (target) => {
        let low = 0, high = walls.length;
        while (low < high) {
            let mid = Math.floor((low + high) / 2);
            if (walls[mid] < target) low = mid + 1;
            else high = mid;
        }
        return low;
    };

    const upperBound = (target) => {
        let low = 0, high = walls.length;
        while (low < high) {
            let mid = Math.floor((low + high) / 2);
            if (walls[mid] <= target) low = mid + 1;
            else high = mid;
        }
        return low;
    };

    const countWallsInRange = (l, r) => {
        if (l > r) return 0;
        return upperBound(r) - lowerBound(l);
    };

    const dp = Array.from({ length: n }, () => [0, 0]);

    const INF = 2e18;
    const pos0 = rData[0].pos;
    const dist0 = rData[0].dist;
    let nextR = (n > 1) ? rData[1].pos : INF;

    dp[0][0] = countWallsInRange(pos0 - dist0, pos0);
    dp[0][1] = countWallsInRange(pos0, Math.min(pos0 + dist0, nextR - 1));

    for (let i = 1; i < n; i++) {
        const curP = rData[i].pos;
        const curD = rData[i].dist;
        const preP = rData[i - 1].pos;
        const preD = rData[i - 1].dist;
        nextR = (i + 1 < n) ? rData[i + 1].pos : INF;

        const rGain = countWallsInRange(curP, Math.min(curP + curD, nextR - 1));
        dp[i][1] = Math.max(dp[i - 1][0], dp[i - 1][1]) + rGain;

        const lLim = Math.max(curP - curD, preP + 1);
        const lGain = countWallsInRange(lLim, curP);
        const caseLeft = dp[i - 1][0] + lGain;
        const overR = Math.min(preP + preD, curP - 1);
        const overlap = countWallsInRange(lLim, overR);
        const caseRight = dp[i - 1][1] + lGain - overlap;

        dp[i][0] = Math.max(caseLeft, caseRight);
    }

    return Math.max(dp[n - 1][0], dp[n - 1][1]);
};