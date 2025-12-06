/**
3578. Count Partitions With Max-Min Difference at Most K
    You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.

    Return the total number of ways to partition nums under this condition.

    Since the answer may be too large, return it modulo 109 + 7.

    

    Example 1:

    Input: nums = [9,4,1,3,7], k = 4

    Output: 6

    Explanation:

    There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:

    [[9], [4], [1], [3], [7]]
    [[9], [4], [1], [3, 7]]
    [[9], [4], [1, 3], [7]]
    [[9], [4, 1], [3], [7]]
    [[9], [4, 1], [3, 7]]
    [[9], [4, 1, 3], [7]]
*/


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countPartitions = function(nums, k) {
    const MOD = 1000000007;
    let n = nums.length;
    let dp = Array(n + 1).fill(0);
    dp[0] = 1;

    let maxq = [], minq = [];
    let left = 0;
    let total = 0;

    for (let i = 0; i < n; i++) {
        while (maxq.length > 0 && nums[maxq[maxq.length - 1]] <= nums[i]) {
            maxq.pop();
        }

        while (minq.length > 0 && nums[minq[minq.length - 1]] >= nums[i]) {
            minq.pop();
        }
        maxq.push(i);
        minq.push(i);

        while (nums[maxq[0]] - nums[minq[0]] > k) {
            if (maxq[0] === left) maxq.shift();
            if (minq[0] === left) minq.shift();
            total = (total - dp[left] + MOD) % MOD;
            left++;
        }

        total = (total + dp[i]) % MOD;
        dp[i + 1] = total;
    }

    return dp[n];
};