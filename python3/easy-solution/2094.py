"""
2094. Finding 3-Digits Even Numbers
    You are given an integer array digits, where each element is a digit. The array may contain duplicates.
    You need to find all the unique integers that follow the given requirements:
    The integer consists of the concatenation of three elements from digits in any arbitrary order.
    The integer does not have leading zeros.
    The integer is even.
    For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.
    Return a sorted array of the unique integers.

    Example :
    Input: digits = [2,1,3,0]
    Output: [102,120,130,132,210,230,302,310,312,320]
    Explanation: All the possible integers that follow the requirements are in the output array. 
    Notice that there are no odd integers or integers with leading zeros.
"""

from typing import List

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        res = set()
        for i in range(len(digits)):
            for j in range(len(digits)):
                for k in range(len(digits)):
                    if i != j and j != k and i != k:
                        nums = digits[i] * 100 + digits[j] * 10 + digits[k]
                        if digits[i] != 0 and nums % 2 == 0:
                            res.add(nums)
        return sorted(res)


# Another solution using Counter 
"""
from collections import Counter
class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        counter = Counter(digits)
        ans = []
        for i in range(100, 1000, 2):
            i0 = i % 10
            i1 = (i // 10) % 10
            i2 = i // 100
            counter[i0] -= 1
            counter[i1] -= 1
            counter[i2] -= 1
            if counter[i0] >= 0 and counter[i1] >= 0 and counter[i2] >= 0:
                ans.append(i)
            counter[i0] += 1
            counter[i1] += 1
            counter[i2] += 1
        return ans
"""