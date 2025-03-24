"""
3169. Count Days Without Meetings
    You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
    Return the count of days when the employee is available for work but no meetings are scheduled.
    Note: The meetings may overlap.
    Example :
    Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
"""

from typing import List

class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort(key = lambda x : x[0])
        res = 0
        end = 0
        for start, finish in meetings:
            if start > end:
                res += start - end - 1
            end = max(end, finish)
        if days > end:
            res += days - end
        return res

