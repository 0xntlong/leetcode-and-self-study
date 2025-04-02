/**
2873. Maximum Value of an Ordered Triplet I
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
    const n = nums.length;
    let L = new Array(n).fill(0);
    let R = new Array(n).fill(0);
    
    for (let i = 1; i < n; i++){
        L[i] = Math.max(L[i - 1], nums[i - 1]);
    }
    for (let i = n - 2; i >= 0; i--){
        R[i] = Math.max(R[i + 1], nums[i + 1]);
    }
    let max_value = 0; 
    for (let i = 1; i < n - 1; i++){
        max_value = Math.max(max_value, (L[i] - nums[i]) * R[i]);
    }
    return max_value;
};