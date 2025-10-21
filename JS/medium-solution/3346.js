/*
3346. Maximum Frequency of an Element After Performing Operations I
    You are given an integer array nums and two integers k and numOperations.
    You must perform an operation numOperations times on nums, where in each operation you:
    Select an index i that was not selected in any previous operations.
    Add an integer in the range [-k, k] to nums[i].
    Return the maximum possible frequency of any element in nums after performing the operations.

    Example :
    Input: nums = [1,4,5], k = 1, numOperations = 2
    Output: 2
    Explanation:
    We can achieve a maximum frequency of two by:
    Adding 0 to nums[1]. nums becomes [1, 4, 5].
    Adding -1 to nums[2]. nums becomes [1, 4, 4].
*/



/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} numOperations
 * @return {number}
 */
var maxFrequency = function(nums, k, numOperations) {
    let M = Math.max(...nums);
    let dp = new Array(M + 1).fill(0);
    let prev = 0, ans = 0;
    for (let i of nums) {
        dp[i]++;
    }
    let curr = 0;
    for (let i = 0; i < k && i <= M; i++) {
        curr += dp[i];
    }
    for (let i = 0; i <= M; i++) {
        curr -= dp[i];
        if (i + k <= M) {
            curr += dp[i + k];
        }
        if (i > 0) {
            prev += dp[i - 1];
        }
        if (i > k + 1) {
            prev -= dp[i - k - 1];
        }
        ans = Math.max(ans, dp[i] + Math.min(numOperations, prev + curr));
    }
    return ans;
};