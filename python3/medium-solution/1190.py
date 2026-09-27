"""
1190. Reverse Substrings Between Each Pair of Parentheses
    You are given a string s that consists of lower case English letters and brackets.
    Reverse the strings in each pair of matching parentheses, starting from the innermost one.
    Your result should not contain any brackets.
    Example :
    Input: s = "(abcd)"
    Output: "dcba"
"""

class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = [""]

        for ch in s:
            if ch == '(':
                stack.append("")
            elif ch == ')':
                temp = stack.pop()
                stack[-1] += temp[::-1]
            else:
                stack[-1] += ch

        return stack[0]