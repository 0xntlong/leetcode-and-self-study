"""
 * 3761. Minimum Absolute Distance Between Mirror Pairs
    You are given an integer array nums.

    A mirror pair is a pair of indices (i, j) such that:

    0 <= i < j < nums.length, and
    reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. Leading zeros are omitted after reversing, for example reverse(120) = 21.
    Return the minimum absolute distance between the indices of any mirror pair. The absolute distance between indices i and j is abs(i - j).

    If no mirror pair exists, return -1.

    

    Example 1:

    Input: nums = [12,21,45,33,54]

    Output: 1

    Explanation:

    The mirror pairs are:

    (0, 1) since reverse(nums[0]) = reverse(12) = 21 = nums[1], giving an absolute distance abs(0 - 1) = 1.
    (2, 4) since reverse(nums[2]) = reverse(45) = 54 = nums[4], giving an absolute distance abs(2 - 4) = 2.
    The minimum absolute distance among all pairs is 1.

"""
from typing import List


class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        hash_map = {}
        mini = float("inf")
        for i, num in enumerate(nums):
            if num in hash_map:
                temp = i - hash_map[num]
                mini = min(mini,temp)
            hash_map[int(str(num)[::-1])] = i
        return -1 if mini == float("inf") else mini