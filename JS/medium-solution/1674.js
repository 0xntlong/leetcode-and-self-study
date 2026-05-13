/**
1674. Minimum Moves to Make Array Complementary
    You are given an integer array nums of even length n and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.
    The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.
    Return the minimum number of moves required to make nums complementary.

    Example :
    Input: nums = [1,2,4,3], limit = 4
    Output: 1
    Explanation: In 1 move, you can change nums to [1,2,2,3] (underlined elements are changed).
    nums[0] + nums[3] = 1 + 3 = 4.
    nums[1] + nums[2] = 2 + 2 = 4.
    nums[2] + nums[1] = 2 + 2 = 4.
    nums[3] + nums[0] = 3 + 1 = 4.
    Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.
 */


/**
 * @param {number[]} nums
 * @param {number} limit
 * @return {number}
 */
var minMoves = function(nums, limit) {
    const n = nums.length;
    const dp = new Array(2 * limit + 2).fill(0);
    for (let i = 0; i < n / 2; i++) {
        const mini = Math.min(nums[i], nums[n - 1 - i]);
        const maxi = Math.max(nums[i], nums[n - 1 - i]);
        dp[2] += 2;
        dp[mini + 1] -= 1;
        dp[mini + maxi] -= 1;
        dp[mini + maxi + 1] += 1;
        dp[maxi + limit + 1] += 1;
    }
    let res = n;
    let moves = 0;
    for (let target = 2; target <= 2 * limit; target++) {
        moves += dp[target];
        res = Math.min(res, moves);
    }
    return res;
};