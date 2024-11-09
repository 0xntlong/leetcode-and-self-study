"""
1614. Maximum Nesting Depth of the Parentheses
    Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

    Example :
    Input: s = "(1+(2*3)+((8)/4))+1"
    Output: 3
    Explanation:
    Digit 8 is inside of 3 nested parentheses in the string.
"""

class Solution:
    def maxDepth(self, s: str) -> int:
        stack = []
        depth = 0
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(s[i])
                if depth < len(stack):
                    depth = len(stack)
            elif s[i] == ')':
                stack.pop()
        return depth