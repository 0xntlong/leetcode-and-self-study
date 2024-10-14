"""
20. Valid Parentheses
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
        
    Example:
    Input: s = "()"
    Output: true
"""

class Solution:
    def isValid(self, s: str) -> bool:
            sym = []
            if(s[0]==')' or s[0]==']' or s[0]=='}'):
                return False
            for i in s:
                if (i=='(' or i=='[' or i=='{'):
                    sym.append(i)
                elif(len(sym)!= 0 and (sym[-1]=='(' or sym[-1]=='[' or sym[-1]=='{')):
                    if((i==')' and sym[-1]=='(') or (i==']' and sym[-1]=='[') or (i=='}' and sym[-1]=='{')):
                        sym.pop()
                    else:
                        return False
                else:
                    return False
            if(len(sym)==0):
                return True
            return False