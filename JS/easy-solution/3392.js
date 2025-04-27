/**
3392. Count Subarrays of Length Three With a Condition
    Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.
    Example :
    Input: nums = [1,2,1,4,1]
    Output: 1
    Explanation:
    Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.
 */


/**
 * @param {number[]} nums
 * @return {number}
 */
var countSubarrays = function(nums) {
    let n = nums.length;
    let count = 0;
    for (let i = 2; i < n; i++){
        if ((nums[i - 2] + nums[i]) * 2 === nums[i - 1]){
            count++;
        }
    }
    return count;
};