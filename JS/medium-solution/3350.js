/*
3350. Adjacent Increasing Subarrays Detection II
    Given an array nums of n integers, your task is to find the maximum value of k for which there exist two adjacent subarrays of length k each, such that both subarrays are strictly increasing. Specifically, check if there are two subarrays of length k starting at indices a and b (a < b), where:
    Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
    The subarrays must be adjacent, meaning b = a + k.
    Return the maximum possible value of k.

    A subarray is a contiguous non-empty sequence of elements within an array.
    Example :
    Input: nums = [2,5,7,8,9,2,3,4,3,1]
    Output: 3
    Explanation:
    The subarray starting at index 2 is [7, 8, 9], which is strictly increasing.
    The subarray starting at index 5 is [2, 3, 4], which is also strictly increasing.
    These two subarrays are adjacent, and 3 is the maximum possible value of k for which two such adjacent strictly increasing subarrays exist.
*/


/**
 * @param {number[]} nums
 * @return {number}
 */
var maxIncreasingSubarrays = function(nums) {
    const n = nums.length;
    if (n < 2) return 0;
    const L = Array(n).fill(1);
    const R = Array(n).fill(1);
    for (let i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1])
            L[i] = L[i - 1] + 1;
    }

    for (let i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1])
            R[i] = R[i + 1] + 1;
    }

    let res = 0;
    for (let i = 0; i < n - 1; i++) {
        res = Math.max(res, Math.min(L[i], R[i + 1]));
    }

    return res;
};