"""
2605. Form Smallest Number From Two Digit Arrays
    Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.

    Example :
    Input: nums1 = [4,1,3], nums2 = [5,7]
    Output: 15
    Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.
"""

from typing import List
class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        set1, set2 = set(nums1), set(nums2)

        common = set1 & set2
        if common:
            return min(common)
        
        min1, min2 = min(nums1), min(nums2)
        return min(min1 * 10 + min2, min2 * 10 + min1)