"""
1360. Number of Days Between Two Dates
    Write a program to count the number of days between two dates.
    The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.
    
    Example :
    Input: date1 = "2019-06-29", date2 = "2019-06-30"
    Output: 1
"""

from datetime import datetime as dt
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        d1 = dt(*[int (i) for i in date1.split('-')])
        d2 = dt(*[int (i) for i in date2.split('-')])
        return abs((d2 - d1).days)


