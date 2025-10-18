/**
3397. Maximum Number of Distinct Elements After Operations
    You are given an integer array nums and an integer k.
    You are allowed to perform the following operation on each element of the array at most once:
    Add an integer in the range [-k, k] to the element.
    Return the maximum possible number of distinct elements in nums after performing the operations.

    Example 1:
    Input: nums = [1,2,2,3,3,4], k = 2
    Output: 6
    Explanation:
    nums changes to [-1, 0, 1, 2, 3, 4] after performing operations on the first four elements.
 */



/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxDistinctElements = function(nums, k) {
    nums.sort((a, b) => a - b);
    let res = 0;
    let prev = -Infinity;
    for (const i of nums){
        if (prev < i - k){
            prev = i - k;
            res++;
        } else if ( prev < i + k) {
            prev = prev + 1;
            res++;
        }
    }
    return res;
};