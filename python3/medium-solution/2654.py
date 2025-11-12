"""
2654. Minimum Number of Operations to Make All Array Elements Equal to 1
    You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:
    Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
    Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.
    The gcd of two integers is the greatest common divisor of the two integers.

    Example :
    Input: nums = [2,6,3,4]
    Output: 4
    Explanation: We can do the following operations:
    - Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
    - Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
    - Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
    - Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
"""

from typing import List
class Solution:
    def gcd(self, a, b):
        if b == 0:
            return abs(a)
        else:
            return self.gcd(b, a % b)

    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        cnt1 = nums.count(1)
        if cnt1:
            return n - cnt1
        res = float("inf")
        for l in range(n):
            g = nums[l]
            for r in range(l + 1, n):
                g = self.gcd(g, nums[r])
                if g == 1:
                    res = min(res, r - l + (n - 1))
                    break
        
        return res if res != float("inf") else -1