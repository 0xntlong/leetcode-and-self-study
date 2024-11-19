"""
2461. Maximum Sum of Distinct Subarrays With Length K
    You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
    The length of the subarray is k, and
    All the elements of the subarray are distinct.
    Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :
    Input: nums = [1,5,4,2,9,9,9], k = 3
    Output: 15
    Explanation: The subarrays of nums with length 3 are:
    - [1,5,4] which meets the requirements and has a sum of 10.
    - [5,4,2] which meets the requirements and has a sum of 11.
    - [4,2,9] which meets the requirements and has a sum of 15.
    - [2,9,9] which does not meet the requirements because the element 9 is repeated.
    - [9,9,9] which does not meet the requirements because the element 9 is repeated.
    We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
"""

from typing import List
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        Set = set()
        curr_sum = 0
        max_sum = 0
        l = 0
        for r in range(n):
            if nums[r] not in Set:
                curr_sum += nums[r]
                Set.add(nums[r])
                if r - l + 1 == k:
                    if curr_sum > max_sum:
                        max_sum = curr_sum
                    curr_sum -= nums[l]
                    Set.remove(nums[l])
                    l += 1
            else:
                while nums[l] != nums[r]:
                    curr_sum -= nums[l]
                    Set.remove(nums[l])
                    l += 1
                l += 1
        return max_sum