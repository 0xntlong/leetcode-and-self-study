/*
1984. Minimum Difference Between Highest and Lowest of K Scores
    You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.
    Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.
    Return the minimum possible difference.

    Example :
    Input: nums = [90], k = 1
    Output: 0
    Explanation: There is one way to pick score(s) of one student:
    - [90]. The difference between the highest and lowest score is 90 - 90 = 0.
    The minimum possible difference is 0.
*/


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minimumDifference = function(nums, k) {
    if (k === 1) 
        return 0;

    nums.sort((a, b) => a - b);
    const n = nums.length;
    let res = Infinity;

    for (let i = 0; i <= n - k; i++) {
        const diff = nums[i + k - 1] - nums[i];
        if (diff < res) res = diff;
    }
    return res;
};