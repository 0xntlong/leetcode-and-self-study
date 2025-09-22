/**
3005. Count Elements With Maximum Frequency
    You are given an array nums consisting of positive integers.

    Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

    The frequency of an element is the number of occurrences of that element in the array.

    

    Example:

    Input: nums = [1,2,2,3,1,4]
    Output: 4
    Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
    So the number of elements in the array with maximum frequency is 4.
 */




/**
 * @param {number[]} nums
 * @return {number}
 */
var maxFrequencyElements = function(nums) {
    const freq = new Map();
    for (const n of nums){
        freq.set(n, (freq.get(n) || 0) + 1);
    }
    let maxFreq = 0;
    for (const v of freq.values()){
        maxFreq = Math.max(maxFreq, v);
    }
    let total = 0;
    for (const v of freq.values()){
        if (v === maxFreq){
            total += v;
        }
    }
    return total;
};