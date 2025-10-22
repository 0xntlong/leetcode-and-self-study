"""
3347. Maximum Frequency of an Element After Performing Operations II
    You are given an integer array nums and two integers k and numOperations.
    You must perform an operation numOperations times on nums, where in each operation you:
    Select an index i that was not selected in any previous operations.
    Add an integer in the range [-k, k] to nums[i].
    Return the maximum possible frequency of any element in nums after performing the operations.

    Example :
    Input: nums = [1,4,5], k = 1, numOperations = 2
    Output: 2
    Explanation:
    We can achieve a maximum frequency of two by:
    Adding 0 to nums[1], after which nums becomes [1, 4, 5].
    Adding -1 to nums[2], after which nums becomes [1, 4, 4].
"""


from typing import List
import bisect
from collections import Counter

class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        if not nums:
            return 0
        nums.sort()
        n = len(nums)
        freq = Counter(nums)
        ans = 1
        for key, val in freq.items():
            low = key - k 
            high = key + k
            left = bisect.bisect_left(nums, low)
            right = bisect.bisect_right(nums, high)
            in_range = right - left
            visited = in_range - val
            min_loop = min(visited, numOperations)
            ans = max(ans, val + min_loop)
        l = 0
        for r in range(n):
            while l <= r and nums[r] - nums[l] > 2 * k:
                l += 1
            w = r - l + 1
            ans = max(ans, min(w, numOperations))
        return ans