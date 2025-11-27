/**
3381. Maximum Subarray Sum With Length Divisible by K
    You are given an array of integers nums and an integer k.
    Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

    Example :
    Input: nums = [1,2], k = 1
    Output: 3
    Explanation:
    The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.
 */



function maxSubarraySum(nums: number[], k: number): number {
    const n = nums.length;
    const min_prefix: number[] = new Array(k).fill(Number.MAX_SAFE_INTEGER);
    let prefix = 0;
    let res = Number.NEGATIVE_INFINITY;
    min_prefix[k - 1] = 0;

    for (let i = 0; i < n; i++) {
        prefix += nums[i];
        let mod_min = min_prefix[i % k];
        res = Math.max(res, prefix - mod_min);
        mod_min = Math.min(prefix, mod_min);
        min_prefix[i % k] = mod_min;
    }

    return res;
};