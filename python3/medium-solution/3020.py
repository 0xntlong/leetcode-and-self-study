"""
3020. Find the Maximum Number of Elements in Subset
    You are given an array of positive integers nums.
    You need to select a subset of nums which satisfies the following condition:
    You can place the selected elements in a 0-indexed array such that it follows the pattern: [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2). For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
    Return the maximum number of elements in a subset that satisfies these conditions.
    Example:
    Input: nums = [5,4,1,2,2]
    Output: 3
    Explanation: We can select the subset {4,2,2}, which can be placed in the array as [2,4,2] which follows the pattern and 22 == 4. Hence the answer is 3.
"""


from typing import List
from collections import Counter

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        count = Counter(nums)
        res = 0
        for key in count.keys():
            if key == 1:
                total = count[key] if count[key] % 2 else count[key] - 1
            else:
                total = 0
                while count[key] >= 2 and key * key in count:
                    total += 2
                    key = key * key
                total += 1
            res = max(res, total)
        return res