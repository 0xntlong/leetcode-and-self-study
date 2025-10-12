"""
3539. Find Sum of Array Product of Magical Sequences
    You are given two integers, m and k, and an integer array nums.
    A sequence of integers seq is called magical if:
    seq has a size of m.
    0 <= seq[i] < nums.length
    The binary representation of 2seq[0] + 2seq[1] + ... + 2seq[m - 1] has k set bits.
    The array product of this sequence is defined as prod(seq) = (nums[seq[0]] * nums[seq[1]] * ... * nums[seq[m - 1]]).
    Return the sum of the array products for all valid magical sequences.
    Since the answer may be large, return it modulo 10^9 + 7.
    A set bit refers to a bit in the binary representation of a number that has a value of 1.

    Example :
    Input: m = 5, k = 5, nums = [1,10,100,10000,1000000]
    Output: 991600007
    Explanation:
    All permutations of [0, 1, 2, 3, 4] are magical sequences, each with an array product of 10^13.
"""

from typing import List
from functools import lru_cache
import math

class Solution:
    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        MOD = 10**9 + 7 
        @lru_cache(None)
        def dp(m_rem, k_rem, i, flag):
            if m_rem < 0 or k_rem < 0 or m_rem + flag.bit_count() < k_rem:
                return 0
            if m_rem == 0:
                if k_rem == flag.bit_count():
                    return 1
                else:
                    return 0
            if i >= len(nums):
                return 0
            res = 0
            for c in range(m_rem + 1):
                mul = math.comb(m_rem, c) * pow(nums[i], c, MOD) % MOD
                new_flag = flag + c
                res += mul * dp(m_rem - c, k_rem - (new_flag % 2), i + 1, new_flag // 2)
            return res % MOD
        return dp(m, k, 0, 0)