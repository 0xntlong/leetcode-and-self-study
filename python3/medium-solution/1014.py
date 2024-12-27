"""
1014. Best Sightseeing Pair
    You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
    The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
    Return the maximum score of a pair of sightseeing spots.

    Example :
    Input: values = [8,1,5,2,6]
    Output: 11
    Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
"""

from typing import List
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        
        # max_sum = 0
        # n = len(values)
        # idx = values[0]
        # for i in range(1, n):
        #     max_sum = max(max_sum, idx + values[i] - i)
        #     idx = max(idx, values[i] + i)
        # return max_sum

        # n = len(values)
        # dp, score = 0, 0
        # for i, idx in enumerate(values):
        #     score = max(score, dp + idx - i)
        #     dp = max(dp, idx + i)
        # return score

        score = 0
        idx = values[0]
        for i in range(1, len(values)):
            idx -= 1
            j = values[i]
            score = max(score, idx + j)
            idx = max(idx, j)
        return score