"""
32. Longest Valid Parentheses
    Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
    Example :
    Input: s = "(()"
    Output: 2
    Explanation: The longest valid parentheses substring is "()".
"""


class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]
        max_len = 0

        for i, c in enumerate(s):
            if c == '(':
                stack.append(i)
            else:
                stack.pop()

                if not stack:
                    stack.append(i)
                else:
                    max_len = max(max_len, i - stack[-1])

        return max_len