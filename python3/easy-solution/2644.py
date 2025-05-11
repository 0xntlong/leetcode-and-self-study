"""
2644. Find the Maximum Divisibility Score
    You are given two integer arrays nums and divisors.
    The divisibility score of divisors[i] is the number of indices j such that nums[j] is divisible by divisors[i].
    Return the integer divisors[i] with the maximum divisibility score. If multiple integers have the maximum score, return the smallest one.
    Example :
    Input: nums = [2,9,15,50], divisors = [5,3,7,2]
    Output: 2
    Explanation:
    The divisibility score of divisors[0] is 2 since nums[2] and nums[3] are divisible by 5.
    The divisibility score of divisors[1] is 2 since nums[1] and nums[2] are divisible by 3.
    The divisibility score of divisors[2] is 0 since none of the numbers in nums is divisible by 7.
    The divisibility score of divisors[3] is 2 since nums[0] and nums[3] are divisible by 2.
    As divisors[0], divisors[1], and divisors[3] have the same divisibility score, we return the smaller one which is divisors[3].
"""


from typing import List
import math
from collections import Counter

class Solution:
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        min_num = min(nums)
        max_num = max(nums)
        counter = Counter(nums)
        div_score = {}
        for d in divisors:
            count = 0
            gen = range(d * math.ceil(min_num / d), max_num + 1, d)
            if len(gen) < len(counter):
                for x in gen:
                    if x in counter:
                        count += counter[x]
            else:
                for x, k in counter.items():
                    if math.gcd(x, d) == d:
                        count += k
            div_score[d] = count
        max_score = float("-inf")
        max_item = float("inf")
        for item, score in div_score.items():
            if score > max_score or (score == max_score and item < max_item):
                max_score = score
                max_item = item
        return max_item