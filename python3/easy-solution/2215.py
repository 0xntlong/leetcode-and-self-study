"""
2215. Find the Difference of Two Arrays
    Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
    answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
    answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
    Note that the integers in the lists may be returned in any order.

    Example :
    Input: nums1 = [1,2,3], nums2 = [2,4,6]
    Output: [[1,3],[4,6]]
    Explanation:
    For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
    For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
"""

from typing import List
class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        nums1.sort()
        nums2.sort()
        n1 , n2 = len(nums1), len(nums2)
        i, j = 0, 0
        dis1, dis2 = [], []
        while i < n1 and j < n2:
            if i > 0 and nums1[i] == nums1[i - 1]:
                    i += 1
                    continue
            if j > 0 and nums2[j] == nums2[j - 1]:
                    j += 1
                    continue
            if nums1[i] == nums2[j]:
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                dis1.append(nums1[i])
                i += 1
            else :
                dis2.append(nums2[j])
                j += 1
        while i < n1:
            if i > 0 and nums1[i] == nums1[i - 1]:
                i += 1
                continue
            dis1.append(nums1[i])
            i += 1
        while j < n2:
            if j > 0 and nums2[j] == nums2[j -1]:
                j += 1
                continue
            dis2.append(nums2[j])
            j += 1
        return [dis1, dis2]               