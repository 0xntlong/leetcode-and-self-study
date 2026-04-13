/*
1848. Minimum Distance to the Target Element
    Given an integer array nums (0-indexed) and two integers target and start, find an index i such that nums[i] == target and abs(i - start) is minimized. Note that abs(x) is the absolute value of x.
    Return abs(i - start).
    It is guaranteed that target exists in nums.

    Example :
    Input: nums = [1,2,3,4,5], target = 5, start = 3
    Output: 1
    Explanation: nums[4] = 5 is the only value equal to target, so the answer is abs(4 - 3) = 1.
*/



/**
 * @param {number[]} nums
 * @param {number} target
 * @param {number} start
 * @return {number}
 */
var getMinDistance = function(nums, target, start) {
    let minDist = Infinity;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === target) {
            minDist = Math.min(minDist, Math.abs(i - start));
        }
    }
    return minDist;
};