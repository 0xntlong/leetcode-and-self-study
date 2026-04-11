/**
3741. Minimum Distance Between Three Equal Elements II
    You are given an integer array nums.
    A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].
    The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.
    Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

    Example :
    Input: nums = [1,2,1,1,3]
    Output: 6
    Explanation:
    The minimum distance is achieved by the good tuple (0, 2, 3).
    (0, 2, 3) is a good tuple because nums[0] == nums[2] == nums[3] == 1. Its distance is abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6.
 */



function minimumDistance1(nums: number[]): number {
    const n: number = nums.length;
    const last: number[] = new Array(n + 1).fill(-1);
    const second: number[] = new Array(n + 1).fill(-1);
    let minDist: number = Infinity;

    for (let i = 0; i < n; i++) {
        const num: number = nums[i];
        if (second[num] !== -1) {
            const dist: number = i - second[num];
            if (dist < minDist) {
                minDist = dist;
            }
        }
        second[num] = last[num];
        last[num] = i;
    }

    return minDist === Infinity ? -1 : 2 * minDist;
};