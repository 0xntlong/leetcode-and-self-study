"""
2145. Count the Hidden Sequences
    You are given a 0-indexed array of n integers differences, which describes the differences between each pair of consecutive integers of a hidden sequence of length (n + 1). More formally, call the hidden sequence hidden, then we have that differences[i] = hidden[i + 1] - hidden[i].
    You are further given two integers lower and upper that describe the inclusive range of values [lower, upper] that the hidden sequence can contain.
    For example, given differences = [1, -3, 4], lower = 1, upper = 6, the hidden sequence is a sequence of length 4 whose elements are in between 1 and 6 (inclusive).
    [3, 4, 1, 5] and [4, 5, 2, 6] are possible hidden sequences.
    [5, 6, 3, 7] is not possible since it contains an element greater than 6.
    [1, 2, 3, 4] is not possible since the differences are not correct.
    Return the number of possible hidden sequences there are. If there are no possible sequences, return 0.

    Example :
    Input: differences = [1,-3,4], lower = 1, upper = 6
    Output: 2
    Explanation: The possible hidden sequences are:
    - [3, 4, 1, 5]
    - [4, 5, 2, 6]
    Thus, we return 2.
"""

from typing import List

class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        n = len(differences)
        x = upper - lower
        total, M, m = 0, 0, 0
        for i in range(n):
            curr = differences[i]
            total += curr
            if total > M:
                M = total
            if total < m:
                m = total
            if M - m > x:
                return 0
        return x - (M - m) + 1
