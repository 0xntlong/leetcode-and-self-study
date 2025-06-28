/**
2099. Find Subsequence of Length K With the Largest Sum
    You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
    Return any such subsequence as an integer array of length k.
    A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

    Example :
    Input: nums = [2,1,3,3], k = 2
    Output: [3,3]
    Explanation:
    The subsequence has the largest sum of 3 + 3 = 6.
 */


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSubsequence = function(nums, k) {
    const n = nums.length;
    if (n == k){
        return nums;
    }
    let res = [];
    for (let i = 0; i < nums.length; i++){
        res.push([nums[i], i]);
    }
    res.sort((a, b) => b[0] - a[0]);
    let minHeap = res.slice(0, k);
    minHeap.sort((a, b) => a[1] - b[1]);
    return minHeap.map((a) => a[0]);
};