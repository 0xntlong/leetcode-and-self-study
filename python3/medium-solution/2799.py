"""
2799. Count Complete Subarrays in an Array
    You are given an array nums consisting of positive integers.
    We call a subarray of an array complete if the following condition is satisfied:
    The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
    Return the number of complete subarrays.
    A subarray is a contiguous non-empty part of an array.
    Example :
    Input: nums = [1,3,1,2,2]
    Output: 4
    Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
"""


from typing import List

class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        res = 0
        left = 0
        k = len(set(nums))
        mp = {}
        for i in range(len(nums)):
            mp[nums[i]] = mp.get(nums[i], 0) + 1
            while len(mp) == k:
                res += len(nums) - i
                mp[nums[left]] -= 1
                if mp[nums[left]] == 0:
                    del mp[nums[left]]
                left += 1
        return res