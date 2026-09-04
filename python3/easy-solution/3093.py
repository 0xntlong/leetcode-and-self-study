"""
3903. Smallest Stable Index I
    You are given an integer array nums of length n and an integer k.
    For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).
    In other words:
    max(nums[0..i]) is the largest value among the elements from index 0 to index i.
    min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
    An index i is called stable if its instability score is less than or equal to k.
    Return the smallest stable index. If no such index exists, return -1.

    Example :
    Input: nums = [5,0,1,4], k = 3
    Output: 3
    Explanation:
    At index 0: The maximum in [5] is 5, and the minimum in [5, 0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
    At index 1: The maximum in [5, 0] is 5, and the minimum in [0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
    At index 2: The maximum in [5, 0, 1] is 5, and the minimum in [1, 4] is 1, so the instability score is 5 - 1 = 4.
    At index 3: The maximum in [5, 0, 1, 4] is 5, and the minimum in [4] is 4, so the instability score is 5 - 4 = 1.
    This is the first index with an instability score less than or equal to k = 3. Thus, the answer is 3.
"""

from typing import List
class Solution:
    def firstStableIndex(self, nums: List[int], k: int) -> int:
        n = len(nums)
        vmax = [nums[0]] * n
        vmin = [nums[-1]] * n
        for i in range(1, n):
            vmax[i] = max(vmax[i - 1], nums[i])
            vmin[n - 1 - i] = min(vmin[n - i], nums[n - 1 - i])
        for i in range(n):
            if vmax[i] - vmin[i] <= k:
                return i
        return -1
    