/**
3349. Adjacent Increasing Subarrays Detection I
    Given an array nums of n integers and an integer k, determine whether there exist two adjacent subarrays of length k such that both subarrays are strictly increasing. Specifically, check if there are two subarrays starting at indices a and b (a < b), where:
    Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
    The subarrays must be adjacent, meaning b = a + k.
    Return true if it is possible to find two such subarrays, and false otherwise.

    Example :
    Input: nums = [2,5,7,8,9,2,3,4,3,1], k = 3
    Output: true
    Explanation:
    The subarray starting at index 2 is [7, 8, 9], which is strictly increasing.
    The subarray starting at index 5 is [2, 3, 4], which is also strictly increasing.
    These two subarrays are adjacent, so the result is true.
 */



/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var hasIncreasingSubarrays = function(nums, k) {
    let prev = 0, curr = 1;
    const n = nums.length;
    for (let i = 0; i < n; i++){
        if (nums[i - 1] < nums[i]){
            curr++;
        } else {
            prev = curr;
            curr = 1;
        }
        if ((curr >= k && prev >= k) || curr === k * 2)
            return true;
    }
    return false;
};