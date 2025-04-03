/**
2874. Maximum Value of an Ordered Triplet II
    You are given a 0-indexed integer array nums.
    Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.
    The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

    Example :
    Input: nums = [12,6,1,2,7]
    Output: 77
    Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
    It can be shown that there are no ordered triplets of indices with a value greater than 77. 
 */



/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumTripletValue = function(nums) {
    let highest = 0;
    let diff = 0;
    let res = 0;
    for (let num of nums){
        res = Math.max(res, diff * num);
        diff = Math.max(diff, highest - num);
        highest = Math.max(highest, num);
    }
    return res;
};