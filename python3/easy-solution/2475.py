"""
2475. Number of Unequal Triplets in Array
    You are given a 0-indexed array of positive integers nums. Find the number of triplets (i, j, k) that meet the following conditions:
    0 <= i < j < k < nums.length
    nums[i], nums[j], and nums[k] are pairwise distinct.
    In other words, nums[i] != nums[j], nums[i] != nums[k], and nums[j] != nums[k].
    Return the number of triplets that meet the conditions.

    Example :
    Input: nums = [4,4,2,4,3]
    Output: 3
    Explanation: The following triplets meet the conditions:
    - (0, 2, 4) because 4 != 2 != 3
    - (1, 2, 4) because 4 != 2 != 3
    - (2, 3, 4) because 2 != 4 != 3
    Since there are 3 triplets, we return 3.
    Note that (2, 0, 4) is not a valid triplet because 2 > 0.
"""

from typing import List
class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        freq = Counter(nums)
        left = 0
        right = len(nums)
        res = 0
        for i in freq.values():
            right -= i
            res += left * i * right
            left += i
        return res