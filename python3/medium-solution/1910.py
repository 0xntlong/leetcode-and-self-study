"""
1910. Remove All Occurrences of a Substring
    Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
    Find the leftmost occurrence of the substring part and remove it from s.
    Return s after removing all occurrences of part.
    A substring is a contiguous sequence of characters in a string.
    Example 
    Input: s = "daabcbaabcbc", part = "abc"
    Output: "dab"
    Explanation: The following operations are done:
    - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
    - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
    - s = "dababc", remove "abc" starting at index 3, so s = "dab".
    Now s has no occurrences of "abc".
"""


class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        curr = []
        n = len(part)
        end = part[-1]

        for i in s:
            curr.append(i)
            if i == end and len(curr) >= n:
                if "".join(curr[-n:]) == part:
                    del curr[-n:]

        return "".join(curr)