/**
2537. Count the Number of Good Subarrays
    Given an integer array nums and an integer k, return the number of good subarrays of nums.
    A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
    A subarray is a contiguous non-empty sequence of elements within an array.
    Example :
    Input: nums = [1,1,1,1,1], k = 10
    Output: 1
    Explanation: The only good subarray is the array nums itself.
 */

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countGood = function(nums, k) {
    const n = nums.length;
    let freq = new Map();
    let cnt = 0;
    let pairs = 0;
    let i = 0;
    for (let j = 0; j < n; j++){
        pairs += (freq.get(nums[j]) || 0);
        freq.set(nums[j], (freq.get(nums[j]) || 0) + 1);
        while (pairs >= k){
            cnt += (n - j);
            freq.set(nums[i], freq.get(nums[i]) - 1);
            pairs -= freq.get(nums[i]);
            i++;
        }
    }
    return cnt;
};