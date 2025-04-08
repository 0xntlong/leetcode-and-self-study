/**
3396. Minimum Number of Operations to Make Elements in Array Distinct
    You are given an integer array nums. You need to ensure that the elements in the array are distinct. To achieve this, you can perform the following operation any number of times:
    Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.
    Note that an empty array is considered to have distinct elements. Return the minimum number of operations needed to make the elements in the array distinct.

    Example :
    Input: nums = [1,2,3,4,2,3,3,5,7]
    Output: 2
    Explanation:
    In the first operation, the first 3 elements are removed, resulting in the array [4, 2, 3, 3, 5, 7].
    In the second operation, the next 3 elements are removed, resulting in the array [3, 5, 7], which has distinct elements.
    Therefore, the answer is 2.
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function(nums) {
    let seen = new Array(101).fill(false);
    for (let i = nums.length - 1; i >= 0; i--){
        if (seen[nums[i]]){
            return Math.floor(i / 3) + 1;
        } else {
            seen[nums[i]] = true;
        }
    }
    return 0;
};