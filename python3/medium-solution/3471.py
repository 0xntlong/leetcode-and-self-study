"""
3471. Find the Largest Almost Missing Integer
    You are given an integer array nums and an integer k.
    An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums
    Return the largest almost missing integer from nums. If no such integer exists, return -1.
    A subarray is a contiguous sequence of elements within an array.
    Example :
    Input: nums = [3,9,2,1,7], k = 3
    Output: 7
    Explanation:
    1 appears in 2 subarrays of size 3: [9, 2, 1] and [2, 1, 7].
    2 appears in 3 subarrays of size 3: [3, 9, 2], [9, 2, 1], [2, 1, 7].
    3 appears in 1 subarray of size 3: [3, 9, 2].
    7 appears in 1 subarray of size 3: [2, 1, 7].
    9 appears in 2 subarrays of size 3: [3, 9, 2], and [9, 2, 1].
    We return 7 since it is the largest integer that appears in exactly one subarray of size k.
"""


from typing import List
class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if k == n:
            return max(nums)
        if k == 1:
            arr = [i for i in nums if nums.count(i) == 1]
        else:
            arr = [i for i in (nums[0], nums[-1]) if nums.count(i) == 1]
        return max(arr) if arr else -1