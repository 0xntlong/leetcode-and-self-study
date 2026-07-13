"""
1291. Sequential Digits
    An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
    Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

    Example :
    Input: low = 100, high = 300
    Output: [123,234]
"""


from typing import List


class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        digits = "123456789"
        res = []
        n = len(str(low))
        m = len(str(high))
        for length in range(n, m + 1):
            for i in range(10 - length):
                num = int(digits[i : i + length])
                if low <= num <= high:
                    res.append(num)
        
        return res