"""
2176. Count Equal and Divisible Pairs in an Array
    Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.

    Example :
    Input: nums = [3,1,2,2,2,1,3], k = 2
    Output: 4
    Explanation:
    There are 4 pairs that meet all the requirements:
    - nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
    - nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
    - nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
    - nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.
"""

from typing import List
from collections import defaultdict
class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        # count = 0
        # for i in range(len(nums)):
        #     for j in range(i + 1,len(nums)):
        #         if nums[i] == nums[j] and (i * j) % k == 0:
        #             count += 1

        # return count

        d = defaultdict(list)
        count = 0
        for i, n in enumerate(nums):
            if n in d:
                for idx in d[n]:
                    if (idx * i) % k == 0:
                        count += 1
            d[n].append(i)
        return count