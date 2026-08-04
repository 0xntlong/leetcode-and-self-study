/**
3731. Find Missing Elements
    You are given an integer array nums consisting of unique integers.
    Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.
    The smallest and largest integers of the original range are still present in nums.
    Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.

    Example :
    Input: nums = [1,4,2,5]
    Output: [3]
    Explanation:
    The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. Among these, only 3 is missing.
 */



/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findMissingElements = function(nums) {
    nums.sort((a, b) => a - b);

    const values = new Set(nums);
    const res = [];

    for (let x = nums[0]; x < nums[nums.length - 1]; x++) {
        if (!values.has(x)) {
            res.push(x);
        }
    }

    return res;
};