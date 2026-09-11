"""
3483. Unique 3-Digit Even Numbers
    You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.
    Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.

    Example :
    Input: digits = [1,2,3,4]
    Output: 12
    Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy of the digit 2.
"""
from collections import defaultdict
from typing import List


class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        freq = defaultdict(int)
        uniq_even = set()
        count = 0
        for d in digits:
            if d % 2 == 0:
                uniq_even.add(d)
            freq[d] += 1

        for e in uniq_even:
            freq[e] -= 1

            keys = [k for k in freq if freq[k]>0]
            for i in range(len(keys)):
                for j in range(i + 1, len(keys)):
                    a , b = keys[i], keys[j]

                    if a != 0:
                        count += 1
                    if b != 0:
                        count += 1
                    
            for num in keys:
                if freq[num] >= 2 and num != 0 :
                    count += 1
            freq[e] += 1
        
        return count