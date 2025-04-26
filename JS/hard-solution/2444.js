/**
2444. Count Subarrays With Fixed Bounds
    You are given an integer array nums and two integers minK and maxK.
    A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
    The minimum value in the subarray is equal to minK.
    The maximum value in the subarray is equal to maxK.
    Return the number of fixed-bound subarrays.
    A subarray is a contiguous part of an array.
    Example :
    Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
    Output: 2
    Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
 */

/**
 * @param {number[]} nums
 * @param {number} minK
 * @param {number} maxK
 * @return {number}
 */
var countSubarrays = function(nums, minK, maxK) {
    let res = 0;
    let maxKidx = -1;
    let minKidx = -1;
    let i = 0;
    for (let x = 0; x < nums.length; x++){
        let y = nums[x];
        if (y < minK || y > maxK){
            i = x + 1;
            continue;
        }
        if (y === maxK){
            maxKidx = x;
        }
        if (y === minK){
            minKidx = x;
        }
        res += Math.max(Math.min(maxKidx, minKidx) - i + 1, 0);
    }
    return res;
};