"""
2540. Minimum Common Value
    Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
    Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

    Example :
    Input: nums1 = [1,2,3], nums2 = [2,4]
    Output: 2
    Explanation: The smallest element common to both arrays is 2, so we return 2.
"""

from typing import List
class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        s1 , s2 = 0 , 0
        while s1 < len(nums1) and s2 < len(nums2):
            if nums1[s1] == nums2[s2]:
                return nums1[s1]
            elif nums1[s1] < nums2[s2]:
                s1 += 1
            else:
                s2 += 1
        return -1
