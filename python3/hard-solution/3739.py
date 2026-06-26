"""
3739. Count Subarrays With Majority Element II
    You are given an integer array nums and an integer target.
    Return the number of subarrays of nums in which target is the majority element.
    The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

    Example :
    Input: nums = [1,2,2,3], target = 2
    Output: 5
    Explanation:
    Valid subarrays with target = 2 as the majority element:
    nums[1..1] = [2]
    nums[2..2] = [2]
    nums[1..2] = [2,2]
    nums[0..2] = [1,2,2]
    nums[1..3] = [2,2,3]
    So there are 5 such subarrays.
"""


from typing import List
class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        freq = [0] * (2 * n + 1)
        freq[n] = 1
        i = n
        res, pref = 0, 0
        for x in nums:
            if x == target:
                pref += freq[i]
                i += 1
            else:
                i -= 1
                pref -= freq[i]
            freq[i] += 1
            res += pref
        return res