/**
3623. Count Number of Trapezoids I
    You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.
    A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.
    Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.
    Since the answer may be very large, return it modulo 109 + 7.

    Example :
    Input: points = [[1,0],[2,0],[3,0],[2,2],[3,2]]
    Output: 3
    Explanation:
    There are three distinct ways to pick four points that form a horizontal trapezoid:
    Using points [1,0], [2,0], [3,2], and [2,2].
    Using points [2,0], [3,0], [3,2], and [2,2].
    Using points [1,0], [3,0], [3,2], and [2,2].
 */



function countTrapezoids(points: number[][]): number {
    const MOD: bigint = 10n ** 9n + 7n;
    const INV2: bigint = (MOD + 1n) / 2n;
    const freq: Map<bigint, bigint> = new Map();
    for (const [x, y] of points) {
        const key: bigint = BigInt(y);
        freq.set(key, (freq.get(key) || 0n) + 1n);
    }
    let totalF: bigint = 0n, sumF2: bigint = 0n;
    for (const f of freq.values()) {
        if (f >= 2n) {
            const pairs: bigint = (f * (f - 1n) / 2n) % MOD;
            totalF = (totalF + pairs) % MOD;
            sumF2 = (sumF2 + (pairs * pairs) % MOD) % MOD;
        }
    }
    let ans: bigint = (totalF * totalF) % MOD;
    ans = (ans - sumF2 + MOD) % MOD;
    ans = (ans * INV2) % MOD;

    return Number(ans);
};