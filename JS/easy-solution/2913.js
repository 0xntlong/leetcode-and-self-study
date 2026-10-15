/**
2913. Subarrays Distinct Element Sum of Squares I
    You are given a 0-indexed integer array nums.
    The distinct count of a subarray of nums is defined as:
    Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].
    Return the sum of the squares of distinct counts of all subarrays of nums.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :
    Input: nums = [1,2,1]
    Output: 15
    Explanation: Six possible subarrays are:
    [1]: 1 distinct value
    [2]: 1 distinct value
    [1]: 1 distinct value
    [1,2]: 2 distinct values
    [2,1]: 2 distinct values
    [1,2,1]: 2 distinct values
    The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.
 */



/**
 * @param {number[]} nums
 * @return {number}
 */
var sumCounts = function(nums) {
    let ans = 0;
    const n = nums.length;

    for (let i = 0; i < n; i++) {
        const seen = new Set();

        for (let j = i; j < n; j++) {
            seen.add(nums[j]);
            const distinct = seen.size;
            ans += distinct * distinct;
        }
    }

    return ans;
};