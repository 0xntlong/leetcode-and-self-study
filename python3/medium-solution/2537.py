"""
2537. Count the Number of Good Subarrays
    Given an integer array nums and an integer k, return the number of good subarrays of nums.
    A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
    A subarray is a contiguous non-empty sequence of elements within an array.
    Example :
    Input: nums = [1,1,1,1,1], k = 10
    Output: 1
    Explanation: The only good subarray is the array nums itself.
"""

from collections import defaultdict
from typing import List
class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        n = len(nums)
        freq = defaultdict(int)
        cnt = 0
        pairs = 0
        i = 0
        for j in range(n):
            pairs += freq[nums[j]]
            freq[nums[j]] += 1
            while pairs >= k:
                cnt += (n - j)
                freq[nums[i]] -= 1
                pairs -= freq[nums[i]]
                i += 1
        return cnt