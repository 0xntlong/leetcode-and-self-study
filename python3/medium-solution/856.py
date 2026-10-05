"""
856. Score of Parentheses
    Given a balanced parentheses string s, return the score of the string.
    The score of a balanced parentheses string is based on the following rule:
    "()" has score 1.
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.
    Example :
    Input: s = "()"
    Output: 1
"""

class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        stack = [0]
        for char in s:
            if char == '(':
                stack.append(0)
            else:
                value = max(2 * stack.pop(), 1)
                stack[-1] += value
        return stack.pop()