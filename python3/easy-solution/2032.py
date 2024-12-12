"""
2032. Two Out of Three
    Given three integer arrays nums1, nums2, and nums3, return a distinct array containing all the values that are present in at least two out of the three arrays. You may return the values in any order.
    
    Example:
    Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
    Output: [3,2]
    Explanation: The values that are present in at least two arrays are:
    - 3, in all three arrays.
    - 2, in nums1 and nums2.
"""

from typing import List
class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        Map = {}
        for i in set(nums1):
            Map[i] = 1 + Map.get(i, 0)
        for i in set(nums2):
            Map[i] = 1 + Map.get(i, 0)
        for i in set(nums3):
            Map[i] = 1 + Map.get(i, 0)
        res = []
        for i in Map:
            if Map[i] >= 2:
                res.append(i)
        return res