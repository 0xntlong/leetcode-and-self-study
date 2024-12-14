"""
2762. Continuous Subarrays
    You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:
    Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
    Return the total number of continuous subarrays.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :
    Input: nums = [5,4,2,4]
    Output: 8
    Explanation: 
    Continuous subarray of size 1: [5], [4], [2], [4].
    Continuous subarray of size 2: [5,4], [4,2], [2,4].
    Continuous subarray of size 3: [4,2,4].
    Thereare no subarrys of size 4.
    Total continuous subarrays = 4 + 3 + 1 = 8.
    It can be shown that there are no more continuous subarrays.
"""

from typing import List
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        freq = {}
        left, right = 0, 0
        count = 0
        while right < len(nums):
            freq[nums[right]] = freq.get(nums[right], 0) + 1
            while max(freq) - min(freq) > 2:
                freq[nums[left]] -= 1
                if freq[nums[left]] == 0:
                    del freq[nums[left]]
                left += 1
            count += right - left + 1
            right += 1
        return count