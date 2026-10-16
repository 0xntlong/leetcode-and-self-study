/**
2916. Subarrays Distinct Element Sum of Squares II
    You are given a 0-indexed integer array nums.
    The distinct count of a subarray of nums is defined as:
    Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].
    Return the sum of the squares of distinct counts of all subarrays of nums.
    Since the answer may be very large, return it modulo 109 + 7.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :
    Input: nums = [1,2,1]
    Output: 15
    Explanation: Six possible subarrays are:
    [1]: 1 distinct value
    [2]: 1 distinct value
    [1]: 1 distinct value
    [1,2]: 2 distinct values
    [2,1]: 2 distinct values
    [1,2,1]: 2 distinct values
    The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.
 */



function sumCounts(nums: number[]): number {
    const MOD = 1000000007;
    const n = nums.length;

    const bit1: number[] = new Array(n + 1).fill(0);
    const bit2: number[] = new Array(n + 1).fill(0);
    const last: number[] = new Array(100001).fill(-1);

    const prefixSum = (k: number): number => {
        let s1 = 0, s2 = 0;
        let index = k;

        while (index > 0) {
            s1 += bit1[index];
            s2 += bit2[index];
            index -= index & -index;
        }

        return k * s1 - s2;
    };

    const addBoundary = (index: number, delta: number): void => {
        const weighted = delta * (index - 1);

        while (index <= n) {
            bit1[index] += delta;
            bit2[index] += weighted;
            index += index & -index;
        }
    };

    let totalDistinct = 0;
    let endingSquares = 0;
    let answer = 0;

    for (let i = 0; i < n; i++) {
        const value = nums[i];
        const p = last[value];

        const affectedSum =
            totalDistinct - prefixSum(p + 1);

        const length = i - p;

        endingSquares =
            (endingSquares + 2 * affectedSum + length) % MOD;

        answer = (answer + endingSquares) % MOD;

        addBoundary(p + 2, 1);
        addBoundary(i + 2, -1);

        totalDistinct += length;
        last[value] = i;
    }

    return answer;
};