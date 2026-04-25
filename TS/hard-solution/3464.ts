/**
3464. Maximize the Distance Between Points on a Square
    You are given an integer side, representing the edge length of a square with corners at (0, 0), (0, side), (side, 0), and (side, side) on a Cartesian plane.
    You are also given a positive integer k and a 2D integer array points, where points[i] = [xi, yi] represents the coordinate of a point lying on the boundary of the square.
    You need to select k elements among points such that the minimum Manhattan distance between any two points is maximized.
    Return the maximum possible minimum Manhattan distance between the selected k points.
    The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
    
    Example 1:
    Input: side = 2, points = [[0,2],[2,0],[2,2],[0,0]], k = 4
    Output: 2
 */


function maxDistance1(side: number, points: number[][], k: number): number {
    const res: number[] = points.map(([x, y]) => {
        if (x === 0) 
            return y;
        if (y === side) 
            return side + x;
        if (x === side) 
            return side * 3 - y;
        return side * 4 - x;
    }).sort((a, b) => a - b);

    const perimeter: number = side * 4;

    const binarySearch = (arr: number[], target: number): number => {
        let l = 0, r = arr.length;
        while (l < r) {
            let mid = Math.floor((l + r) / 2);
            if (arr[mid] < target) 
                l = mid + 1;
            else r = mid;
        }
        return l;
    };

    const check = (n: number): boolean => {
        const m = res.length;
        let idx: number[] = new Array(k).fill(0);
        let curr = res[0];
        for (let i = 1; i < k; i++) {
            let j = binarySearch(res, curr + n);
            if (j === m) 
                return false;
            idx[i] = j;
            curr = res[j];
        }
        if (res[idx[k - 1]] - res[0] <= perimeter - n) 
            return true;

        for (idx[0] = 1; idx[0] < idx[1]; idx[0]++) {
            for (let j = 1; j < k; j++) {
                while (idx[j] < m && res[idx[j]] < res[idx[j - 1]] + n) {
                    idx[j]++;
                }
                if (idx[j] === m) 
                    return false;
            }
            if (res[idx[k - 1]] - res[idx[0]] <= perimeter - n) 
                return true;
        }
        return false;
    };

    let left = 1, right = Math.floor(perimeter / k) + 1;
    while (left + 1 < right) {
        let mid = Math.floor((left + right) / 2);
        if (check(mid)) 
            left = mid;
        else right = mid;
    }
    return left;
};