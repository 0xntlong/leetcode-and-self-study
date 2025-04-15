"""
2179. Count Good Triplets in an Array
    You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].
    A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.
    Return the total number of good triplets.

    Example :
    Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
    Output: 1
    Explanation: 
    There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
    Out of those triplets, only the triplet (0,1,3) satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet.
"""
from typing import List
from sortedcontainers import SortedList # type: ignore


class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        res = 0
        indices = [0] * len(nums1)
        arr = SortedList()

        for i, num in enumerate(nums1):
            indices[num] = i
        for i, num in enumerate(nums2):
            nums1[i] = indices[num]
        for i, num in enumerate(nums1[::-1]):
            indices = arr.bisect(num)
            res += (i - indices) * (num - indices)
            arr.add(num)
        return res 