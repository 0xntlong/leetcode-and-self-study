/**
2419. Longest Subarray With Maximum Bitwise AND
    You are given an integer array nums of size n.
    Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
    In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
    Return the length of the longest such subarray.
    The bitwise AND of an array is the bitwise AND of all the numbers in it.
    A subarray is a contiguous sequence of elements within an array.

    Example :
    Input: nums = [1,2,3,3,2,2]
    Output: 2
    Explanation:
    The maximum possible bitwise AND of a subarray is 3.
    The longest subarray with that value is [3,3], so we return 2.
 */




function longestSubarray(nums: number[]): number {
    const n = nums.length;
    let maxLen = 0;
    let xMax = 0;
    let l = 0, r = 0;
    while (r < n){
        while (r < n && nums[r] === xMax){
            r++;
        }
        if (r === n || nums[r] < xMax){
            maxLen = Math.max(maxLen, r - l);
            l = r + 1;
            r = l;
        } else {
            xMax = nums[r];
            maxLen = 1;
            l = r;
        }
    }
    return maxLen;
};