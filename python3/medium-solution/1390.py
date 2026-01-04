"""
1390. Four Divisors
    Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.
    Example :
    Input: nums = [21,4,7]
    Output: 32
    Explanation: 
    21 has 4 divisors: 1, 3, 7, 21
    4 has 3 divisors: 1, 2, 4
    7 has 2 divisors: 1, 7
    The answer is the sum of divisors of 21 only.

"""

from typing import List

class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        def div_sum(n):
            div = set()
            for i in range(1, int(n ** 0.5) + 1):
                if n % i == 0:
                    div.add(i)
                    div.add(n // i)
                    if len(div) > 4:
                        return 0
            return sum(div) if len(div) == 4 else 0
        res = 0
        for n in nums:
            res += div_sum(n)
        return res