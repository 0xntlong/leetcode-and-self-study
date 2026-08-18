/**
3471. Find the Largest Almost Missing Integer
    You are given an integer array nums and an integer k.
    An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums
    Return the largest almost missing integer from nums. If no such integer exists, return -1.
    A subarray is a contiguous sequence of elements within an array.
    Example :
    Input: nums = [3,9,2,1,7], k = 3
    Output: 7
    Explanation:
    1 appears in 2 subarrays of size 3: [9, 2, 1] and [2, 1, 7].
    2 appears in 3 subarrays of size 3: [3, 9, 2], [9, 2, 1], [2, 1, 7].
    3 appears in 1 subarray of size 3: [3, 9, 2].
    7 appears in 1 subarray of size 3: [2, 1, 7].
    9 appears in 2 subarrays of size 3: [3, 9, 2], and [9, 2, 1].
    We return 7 since it is the largest integer that appears in exactly one subarray of size k.
 */



function largestInteger(nums: number[], k: number): number {
    const n: number = nums.length;

    if (k === n) {
        return Math.max(...nums);
    }

    let arr: number[] = [];

    if (k === 1) {
        arr = nums.filter(
            x => nums.filter(y => y === x).length === 1
        );
    } else {
        arr = [nums[0], nums[n - 1]].filter(
            x => nums.filter(y => y === x).length === 1
        );
    }

    return arr.length ? Math.max(...arr) : -1;
}