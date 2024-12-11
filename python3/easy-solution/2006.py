"""
2006. Count Number of Pairs With Absolute Difference K
    Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
    The value of |x| is defined as:
    x if x >= 0.
    -x if x < 0.

    Example :
    Input: nums = [1,2,2,1], k = 1
    Output: 4
    Explanation: The pairs with an absolute difference of 1 are:
    - [1,2,2,1]
    - [1,2,2,1]
    - [1,2,2,1]
    - [1,2,2,1]
"""

from typing import List
from collections import defaultdict
class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        dic = defaultdict(int)
        res = 0
        for i in nums:
            x, y = i - k, i + k
            if x in dic:
                res += dic[x]
            if y in dic:
                res += dic[y]
            dic[i] += 1
        return res