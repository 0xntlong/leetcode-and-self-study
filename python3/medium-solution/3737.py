"""
3737. Count Subarrays With Majority Element I
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
        balance = 0
        cnt = {0: 1}
        res = 0
        curr = 0
        for i in nums:
            if i == target:
                curr += cnt.get(balance, 0)
                balance += 1
            else:
                balance -= 1
                curr -= cnt.get(balance, 0)
            cnt[balance] = cnt.get(balance, 0) + 1
            res += curr
        return res