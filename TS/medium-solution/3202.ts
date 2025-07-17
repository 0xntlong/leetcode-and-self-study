/**
3202. Find the Maximum Length of Valid Subsequence II
    You are given an integer array nums and a positive integer k.
    A subsequence sub of nums with length x is called valid if it satisfies:
    (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
    Return the length of the longest valid subsequence of nums.

    Example:
    Input: nums = [1,2,3,4,5], k = 2
    Output: 5
    Explanation:
    The longest valid subsequence is [1, 2, 3, 4, 5].
 */



function maximumLength(nums: number[], k: number): number {
    const n = nums.length;
    if (k === 1){
        return n;
    }
    let res = 2;
    const arr = nums.map(num => num % k);
    for (let i = 0; i < k; i++){
        const dp = new Array(k).fill(0);
        for (let j = 0; j < n; j++){
            const mod = arr[j];
            const prev = (i - mod + k) % k;
            dp[mod] = dp[prev] + 1;
            res = Math.max(res, dp[mod]);
        }
    }
    return res;
};