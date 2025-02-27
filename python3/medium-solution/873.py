"""
873. Length of Longest Fibonacci Subsequence
    A sequence x1, x2, ..., xn is Fibonacci-like if:
    n >= 3
    xi + xi+1 == xi+2 for all i + 2 <= n
    Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.
    A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].

    Example :
    Input: arr = [1,2,3,4,5,6,7,8]
    Output: 5
    Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
"""


from typing import List
from collections import defaultdict
class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        idx = {num : i for i, num in enumerate(arr)}
        dp = defaultdict(lambda: 2)
        maxLength = 0
        n = len(arr)

        for i in range(n):
            for j in range(i):
                prev = arr[i] - arr[j]
                if prev in idx and idx[prev] < j:
                    dp[(j, i)] = dp[(idx[prev], j)] + 1
                    maxLength = max(maxLength, dp[(j, i)])
        return maxLength if maxLength > 2 else 0