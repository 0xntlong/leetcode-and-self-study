/**
3355. Zero Array Transformation I
    You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].
    For each queries[i]:
    Select a subset of indices within the range [li, ri] in nums.
    Decrement the values at the selected indices by 1.
    A Zero Array is an array where all elements are equal to 0.
    Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.

    Example :
    Input: nums = [1,0,1], queries = [[0,2]]
    Output: true
    Explanation:
    For i = 0:
    Select the subset of indices as [0, 2] and decrement the values at these indices by 1.
    The array will become [0, 0, 0], which is a Zero Array.
*/



/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {boolean}
 */
var isZeroArray = function(nums, queries) {
    const n = nums.length;
    const freq = new Array(n + 1).fill(0);
    for (let i = 0; i < queries.length; i++){
        let l = queries[i][0];
        let r = queries[i][1];
        freq[l] += 1;
        freq[r + 1] -= 1;
    }
    let rsum = 0;
    for (let i = 0; i < freq.length; i++){
        rsum += freq[i];
        freq[i] = rsum;
        if (nums[i] > freq[i]){
            return false;
        }
    }
    return true;
};