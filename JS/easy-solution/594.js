/**
594. Longest Harmonious Subsequence
    We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
    Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

    Example :
    Input: nums = [1,3,2,2,5,2,3,7]
    Output: 5
    Explanation:
    The longest harmonious subsequence is [3,2,2,2,3].
 */



/**
 * @param {number[]} nums
 * @return {number}
 */
var findLHS = function(nums) {
    const freq = new Map();
    for (const num of nums){
        freq.set(num, (freq.get(num) || 0) + 1);
    }
    let res = 0;
    for (const [key, val] of freq.entries()){
        if (freq.has(key + 1)){
            res = Math.max(res, val + freq.get(key + 1));
        }
    }
    return res;
};