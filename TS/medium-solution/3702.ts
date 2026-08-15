/**
3702. Longest Subsequence With Non-Zero Bitwise XOR
    You are given an integer array nums.
    Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.
    Example :
    Input: nums = [1,2,3]
    Output: 2
    Explanation:
    One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.
 */




function longestSubsequence(nums: number[]): number {
    const n = nums.length;

    if (nums.every(num => num === 0)) {
        return 0;
    }

    let x = 0;

    for (const num of nums) {
        x ^= num;
    }

    return x ? n : n - 1;
};