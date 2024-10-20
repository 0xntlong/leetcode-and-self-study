"""
1106. Parsing A Boolean Expression
    A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:
    't' that evaluates to true.
    'f' that evaluates to false.
    '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
    '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
    '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
    Given a string expression that represents a boolean expression, return the evaluation of that expression.

    It is guaranteed that the given expression is valid and follows the given rules.
    Example:
    Input: expression = "&(|(f))"
    Output: false
    Explanation: 
    First, evaluate |(f) --> f. The expression is now "&(f)".
    Then, evaluate &(f) --> f. The expression is now "f".
    Finally, return false.
"""

class Solution:
    #first approach
    def parseBoolExpr(self, expression: str) -> bool:
        stack = []
        for i in expression:
            if i != ')' and i != ',':
                stack.append(i)
            elif i == ')':
                child = []
                while stack and stack[-1] != '(':
                    operator = stack.pop()
                    child.append( True if operator == 't' else False)
                stack.pop()
                if stack:
                    operator = stack.pop()
                    idx = child[0]
                    if operator == '&':
                        for j in child:
                            idx &= j
                    elif operator == '|':
                        for j in child:
                            idx |= j
                    else:
                        idx = not idx
                    stack.append('t' if idx else 'f')
        return stack[-1] == 't'
    
    #second approach
    def parseBoolExpr(self, expression: str) -> bool:
        stack = []
        for i in expression:
            if i != ')' and i != ',':
                stack.append(i)
            elif i == ')':
                child = []
                while stack and stack[-1] != '(':
                    child.append( True if stack.pop() == 't' else False)
                stack.pop()
                operator = stack.pop()
                if operator == '&':
                    result = all(child)
                elif operator == '|':
                    result = any(child)
                else:
                    result = not child[0]
                stack.append('t' if result else 'f')
        return stack[0] == 't'

    #third approach
    def parseBoolExpr(self, expression: str) -> bool:
        i = 0
        def helper():
            nonlocal i
            idx = expression[i]
            i += 1
            if idx == 't':
                return True
            if idx == 'f':
                return False
            if idx == '!':
                i += 1
                result = not helper()
                i += 1
                return result
            child = []
            i += 1
            while expression[i] != ')':
                if expression[i] != ',':
                    child.append(helper())
                else:
                    i += 1
            i += 1
            if idx == '&':
                return all(child)
            if idx == '|':
                return any(child)
        return helper()