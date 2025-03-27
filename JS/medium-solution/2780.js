/**
2780. Minimum Index of a Valid Split
    An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.
    You are given a 0-indexed integer array nums of length n with one dominant element.
    You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:
    0 <= i < n - 1
    nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
    Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.
    Return the minimum index of a valid split. If no valid split exists, return -1.

    Example :
    Input: nums = [1,2,2,2]
    Output: 2
    Explanation: We can split the array at index 2 to obtain arrays [1,2,2] and [2]. 
    In array [1,2,2], element 2 is dominant since it occurs twice in the array and 2 * 2 > 3. 
    In array [2], element 2 is dominant since it occurs once in the array and 1 * 2 > 1.
    Both [1,2,2] and [2] have the same dominant element as nums, so this is a valid split. 
    It can be shown that index 2 is the minimum index of a valid split. 
 */


/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumIndex = function(nums) {
    const n = nums.length;
    let count = 0;
    let idx = -1;
    for (let i of nums){
        if (count === 0){
            idx = i;
        }
        count += (i === idx) ? 1 : -1;
    }
    const freq = {};
    for (let i of nums){
        freq[i] = (freq[i] || 0) + 1;
    }
    let countFreq = 0;
    for (let i = 0; i < n; i++){
        countFreq += (nums[i] === idx) ? 1 : 0;
        if (countFreq * 2 > (i + 1) && (freq[idx] - countFreq) * 2 > (n - i - 1)){
            return i;
        }
    }
    return -1;
};