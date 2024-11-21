"""
1736. Latest Time by Replacing Hidden Digits
    You are given a string time in the form of  hh:mm, where some of the digits in the string are hidden (represented by ?).
    The valid times are those inclusively between 00:00 and 23:59.
    Return the latest valid time you can get from time by replacing the hidden digits.

    Example :
    Input: time = "2?:?0"
    Output: "23:50"
    Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
"""

class Solution:
    def maximumTime(self, time: str) -> str:
        time = list(time)
        for i in range(len(time)):
            if time[i] == '?':
                if i == 0:
                    time[i] = '2' if time[i + 1] in '?0123' else '1'
                elif i == 1:
                    time[i] = '3' if time[0] == '2' else '9'
                elif i == 3:
                    time[i] = '5'
                else:
                    time[i] = '9'
        return "".join(time)