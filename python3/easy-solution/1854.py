"""
1854. Maximum Population Year
    You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.
    The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.
    Return the earliest year with the maximum population.

    Example :
    Input: logs = [[1993,1999],[2000,2010]]
    Output: 1993
    Explanation: The maximum population is 1, and 1993 is the earliest year with this population.
"""

from typing import List
class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        vals = []
        for x, y in logs:
            vals.append((x, 1))
            vals.append((y, -1))
        ans = prefix = most = 0
        for x, k in sorted(vals):
            prefix += k
            if prefix > most:
                ans = x
                most = prefix
        return ans        