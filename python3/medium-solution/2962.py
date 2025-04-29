"""
2962. Count Subarrays Where Max Element Appears at Least K Times
    You are given an integer array nums and a positive integer k.
    Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
    A subarray is a contiguous sequence of elements within an array.

    Example :
    Input: nums = [1,3,2,3,3], k = 2
    Output: 6
    Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
"""

from typing import List
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        maxElement = max(nums)
        n = len(nums)
        l, r = 0, 0
        res = 0
        count = 0
        while r < n:
            if nums[r] == maxElement:
                count += 1
            while count >= k:
                res += (n - r)
                if nums[l] == maxElement:
                    count -= 1
                l += 1
            r += 1
        return res 