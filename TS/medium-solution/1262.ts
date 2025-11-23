/**
1262. Greatest Sum Divisible by Three
    Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

    Example 1:
    Input: nums = [3,6,5,1,8]
    Output: 18
    Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
*/



function maxSumDivThree(nums: number[]): number {
    let dp: number[] = [0, 0, 0];

    for (let num of nums) {
        const prev = [...dp];
        for (let cur of prev) {
            const s = cur + num;
            dp[s % 3] = Math.max(dp[s % 3], s);
        }
    }
    return dp[0];
};