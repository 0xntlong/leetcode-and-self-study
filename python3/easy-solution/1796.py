"""
1796. Second Largest Digit in a String
    Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
    An alphanumeric string is a string consisting of lowercase English letters and digits.
    Example :
    Input: s = "dfa12321afd"
    Output: 2
    Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
"""

class Solution:
    def secondHighest(self, s: str) -> int:
        digits = []
        for char in s:
            if '0' <= char <= '9':
                digits.append(int(char))
        if len(digits) <= 1:
            return -1
        largest, secondLargest = -1, -1
        for i in digits:
            largest = max(largest, i)
        for i in digits:
            if secondLargest < i < largest:
                secondLargest = i
        return secondLargest