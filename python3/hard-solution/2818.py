"""
2818. Apply Operations to Maximize Score
    You are given an array nums of n positive integers and an integer k.
    Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:
    Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
    Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
    Multiply your score by x.
    Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive.
    The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.
    Return the maximum possible score after applying at most k operations.
    Since the answer may be large, return it modulo 109 + 7.
    Example :
    Input: nums = [8,3,9,3,8], k = 2
    Output: 81
    Explanation: To get a score of 81, we can apply the following operations:
    - Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
    - Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 1, but nums[2] has the smaller index. Hence, we multiply the score by nums[2]. The score becomes 9 * 9 = 81.
    It can be proven that 81 is the highest score one can obtain.
"""

from typing import List
from math import sqrt
from functools import lru_cache

@lru_cache(None)
def isPrimeScore(num):
    score = 0
    if num % 2 == 0:
        score += 1
        while num % 2 == 0:
            num //= 2
    for p in range(3, int(sqrt(num)) + 1, 2):
        if num % p == 0:
            score += 1
            while num % p == 0:
                num //= p
    if num > 1:
        score += 1
    return score 

class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        MOD = 10**9 + 7
        scores = [isPrimeScore(num) for num in nums] + [MOD]
        lefts = [0] * len(nums)
        stack = [-1]
        for i in range(len(nums)):
            while scores[i] > scores[stack[-1]]:
                stack.pop()
            lefts[i] = stack[-1]
            stack.append(i)
        rights = [0] * len(nums)
        stack = [len(nums)]

        for i in reversed(range(len(nums))):
            while scores[i] >= scores[stack[-1]]:
                stack.pop()
            rights[i] = stack[-1]
            stack.append(i)

        max_score = 1
        for num, i in sorted(((num, i) for i, num in enumerate(nums)), reverse = True):
            count = (i - lefts[i]) * (rights[i] - i)
            max_score *= pow(num, min(k, count), MOD )
            max_score %= MOD 
            if count >= k:
                break
            k -= count
        return max_score