"""
678. Valid Parenthesis String
    Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
    The following rules define a valid string:
    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

    Example :
    Input: s = "()"
    Output: true
"""



class Solution:
    def checkValidString(self, s: str) -> bool:
        left = []
        star = []
        n = len(s)

        for i in range(n):
            if s[i] == '(':
                left.append(i)
            elif s[i] == '*':
                star.append(i)
            elif s[i] == ')':
                if left:
                    left.pop()
                elif star:
                    star.pop()
                else:
                    return False

        while left and star and left[-1] < star[-1]:
            left.pop()
            star.pop()

        if len(left) > 0:
            return False

        return True