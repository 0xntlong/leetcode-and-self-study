"""
2040. Kth Smallest Product of Two Sorted Arrays
    Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.

    Example :
    Input: nums1 = [2,5], nums2 = [3,4], k = 2
    Output: 8
    Explanation: The 2 smallest products are:
    - nums1[0] * nums2[0] = 2 * 3 = 6
    - nums1[0] * nums2[1] = 2 * 4 = 8
    The 2nd smallest product is 8.
"""

from bisect import bisect_right, bisect_left
from math import ceil
from typing import List
class Solution:
    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        def pair(x):
            count = 0
            for n1 in nums1:
                if n1 > 0:
                    count += bisect_right(nums2, x // n1)
                elif n1 < 0:
                    count += len(nums2) - bisect_left(nums2, ceil(x / n1))
                elif x >= 0:
                    count += len(nums2)
            return count

        low = -10**10 - 1
        high = 10**10 + 1
        while low + 1 < high:
            mid = (low + high) // 2
            if pair(mid) >= k:
                high = mid
            else:
                low = mid
        return low + 1