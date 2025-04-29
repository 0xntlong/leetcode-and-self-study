/**
2962. Count Subarrays Where Max Element Appears at Least K Times
    You are given an integer array nums and a positive integer k.
    Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
    A subarray is a contiguous sequence of elements within an array.

    Example :
    Input: nums = [1,3,2,3,3], k = 2
    Output: 6
    Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
 */

    function countSubarrays(nums: number[], k: number): number {
        let maxElement = Math.max(...nums);
        let n = nums.length;
        let l = 0, r = 0;
        let res = 0;
        let count = 0;
        while (r < n){
            if (nums[r] === maxElement){
                count++;
            }
            while (count >= k){
                res += (n - r);
                if (nums[l] === maxElement){
                    count--;
                }
                l++;
            }
            r++;
        }
        return res;
    };