/**
3625. Count Number of Trapezoids II
    You are given a 2D integer array points where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.
    Return the number of unique trapezoids that can be formed by choosing any four distinct points from points.
    A trapezoid is a convex quadrilateral with at least one pair of parallel sides. Two lines are parallel if and only if they have the same slope.

    Example 1:
    Input: points = [[-3,2],[3,0],[2,3],[3,2],[2,-3]]
    Output: 2
    Explanation:
    There are two distinct ways to pick four points that form a trapezoid:

    The points [-3,2], [2,3], [3,2], [2,-3] form one trapezoid.
    The points [2,3], [3,2], [3,0], [2,-3] form another trapezoid.
 */



function gcd(a: number, b: number): number {
    a = Math.abs(a);
    b = Math.abs(b);
    while (b !== 0) {
        let tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

function count(map: Map<any, Map<any, number>>): number {
    let ans = 0;

    for (let inner of map.values()) {
        let total = 0;
        for (let val of inner.values()) total += val;

        let rem = total;
        for (let val of inner.values()) {
            rem -= val;
            ans += val * rem;
        }
    }
    return ans;
}

export var countTrapezoids = function(points: number[][]): number {
    const slopes = new Map<number, Map<number, number>>();
    const lines = new Map<number, Map<number, number>>();
    const n = points.length;

    function add(map: Map<number, Map<number, number>>, key: number, des: number): void {
        if (!map.has(key)) map.set(key, new Map());
        const inner = map.get(key);
        inner!.set(des, (inner!.get(des) || 0) + 1);
    }

    for (let i = 0; i < n; i++) {
        let [x1, y1] = points[i];
        for (let j = i + 1; j < n; j++) {
            let [x2, y2] = points[j];
            let dx = x2 - x1;
            let dy = y2 - y1;
            if (dx < 0 || (dx === 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }
            let g = gcd(dx, Math.abs(dy));
            let x = dx / g;
            let y = dy / g;
            let inter = x * y1 - y * x1;
            let key1 = (x << 12) | (y + 2000);
            let key2 = (dx << 12) | (dy + 2000);
            add(slopes, key1, inter);
            add(lines, key2, inter);
        }
    }

    return count(slopes) - Math.floor(count(lines) / 2);
};