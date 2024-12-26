"""
2231. Largest Number After Digit Swaps by Parity
    You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).
    Return the largest possible value of num after any number of swaps.

    Example :
    Input: num = 1234
    Output: 3412
    Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
    Swap the digit 2 with the digit 4, this results in the number 3412.
    Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
    Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
"""


import heapq
class Solution:
    def largestInteger(self, num: int) -> int:
        odd, even = [], []
        digits, res = [], []
        while num > 0:
            n = num % 10
            digits.append(n)
            if n % 2 == 0:
                heapq.heappush(even, -n)
            else:
                heapq.heappush(odd, -n)
            num //= 10
        digits.reverse()
        for d in digits:
            if d % 2 == 0:
                res.append(-heapq.heappop(even))
            else :
                res.append(-heapq.heappop(odd))

        maxNum = 0
        for digit in res:
            maxNum = maxNum * 10 + digit
        return maxNum