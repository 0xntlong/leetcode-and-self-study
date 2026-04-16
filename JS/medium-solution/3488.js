/**
3488. Closest Equal Element Queries
    You are given a circular array nums and an array queries.
    For each query i, you have to find the following:
    The minimum distance between the element at index queries[i] and any other index j in the circular array, where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1.
    Return an array answer of the same size as queries, where answer[i] represents the result for query i.
    Example :
    Input: nums = [1,3,1,4,1,3,2], queries = [0,3,5]
    Output: [2,-1,3]
    Explanation:
    Query 0: The element at queries[0] = 0 is nums[0] = 1. The nearest index with the same value is 2, and the distance between them is 2.
    Query 1: The element at queries[1] = 3 is nums[3] = 4. No other index contains 4, so the result is -1.
    Query 2: The element at queries[2] = 5 is nums[5] = 3. The nearest index with the same value is 1, and the distance between them is 3 (following the circular path: 5 -> 6 -> 0 -> 1).
 */


/**
 * @param {number[]} nums
 * @param {number[]} queries
 * @return {number[]}
 */
var solveQueries = function(nums, queries) {
    const n = nums.length;
    const last = new Map();
    const dp = new Array(n).fill(n);

    for (let i = 0; i < 2 * n; i++) {
        const idx = i % n;
        const num = nums[idx];

        if (last.has(num)) {
            const prev = last.get(num);
            const dist = i - prev;

            dp[idx] = Math.min(dp[idx], dist);
            dp[prev % n] = Math.min(dp[prev % n], dist);
        }

        last.set(num, i);
    }

    return queries.map(q => dp[q] === n ? -1 : dp[q]);
};