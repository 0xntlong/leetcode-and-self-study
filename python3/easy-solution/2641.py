"""
2614. Prime In Diagonal
    You are given a 0-indexed two-dimensional integer array nums.
    Return the largest prime number that lies on at least one of the diagonals of nums. In case, no prime is present on any of the diagonals, return 0.
    Note that:
    An integer is prime if it is greater than 1 and has no positive integer divisors other than 1 and itself.
    An integer val is on one of the diagonals of nums if there exists an integer i for which nums[i][i] = val or an i for which nums[i][nums.length - i - 1] = val.
    In the above diagram, one diagonal is [1,5,9] and another diagonal is [3,5,7].
    Example :
    Input: nums = [[1,2,3],[5,6,7],[9,10,11]]
    Output: 11
    Explanation: The numbers 1, 3, 6, 9, and 11 are the only numbers present on at least one of the diagonals. Since 11 is the largest prime, we return 11.
"""
from typing import List
import math

class Solution:
    def isPrime(self, n):
        if n <= 1:
            return False
        if n == 2:
            return True
        if n % 2 == 0:
            return False
        for i in range(3, math.isqrt(n) + 1, 2):
            if n % i == 0:
                return False
        return True

    def diagonalPrime(self, nums: List[List[int]]) -> int:
        n = len(nums)
        maxI = 0
        for i in range(n):
            if self.isPrime(nums[i][i]):
                maxI = max(maxI, nums[i][i])
            if self.isPrime(nums[i][n - i - 1]):
                maxI = max(maxI, nums[i][n - i - 1])

        return maxI