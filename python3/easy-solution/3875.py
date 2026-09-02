"""
3875. Construct Uniform Parity Array I
    You are given an array nums1 of n distinct integers.
    You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.
    For each index i, you must choose exactly one of the following (in any order):
    nums2[i] = nums1[i]
    nums2[i] = nums1[i] - nums1[j], for an index j != i
    Return true if it is possible to construct such an array, otherwise, return false.

    Example :
    Input: nums1 = [2,3]
    Output: true
    Explanation:
    Choose nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1.
    Choose nums2[1] = nums1[1] = 3.
    nums2 = [-1, 3], and both elements are odd. Thus, the answer is true.
"""

from typing import list
class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        # return True
        odd = 0
        even = 0 
        n = len(nums1)
        for i in nums1:
            if i % 2 == 0:
                even += 1
            else:
                odd += 1
        if even == n or odd == n:
            return True
        elif even >= 1 and odd >= 1:
            return True
        return False