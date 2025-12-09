"""
3583. Count Special Triplets
    You are given an integer array nums.
    A special triplet is defined as a triplet of indices (i, j, k) such that:
    0 <= i < j < k < n, where n = nums.length
    nums[i] == nums[j] * 2
    nums[k] == nums[j] * 2
    Return the total number of special triplets in the array.
    Since the answer may be large, return it modulo 109 + 7.

    Example :
    Input: nums = [6,3,6]
    Output: 1
    Explanation:
    The only special triplet is (i, j, k) = (0, 1, 2), where:
    nums[0] = 6, nums[1] = 3, nums[2] = 6
    nums[0] = nums[1] * 2 = 3 * 2 = 6
    nums[2] = nums[1] * 2 = 3 * 2 = 6

"""

from typing import List
class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        dict1 = {}
        dict2 = {}
        res = 0
        mod = 10**9 + 7
        for num in nums:
            if num % 2 == 0 and num // 2 in dict2:
                res += dict2[num // 2]
                res %= mod
            if num * 2 in dict1:
                if num in dict2:
                    dict2[num] += dict1[num * 2]
                else:
                    dict2[num] = dict1[num * 2]

            if num in dict1:
                dict1[num] += 1
            else:
                dict1[num] = 1
        return res