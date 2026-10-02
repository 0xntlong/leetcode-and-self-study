"""
22. Generate Parentheses
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
    Example :
    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]
"""



class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        result = []

        def dfs(left, right, s):
            if len(s) == n * 2:
                result.append(s)
                return

            if left < n:
                dfs(left + 1, right, s + '(')

            if right < left:
                dfs(left, right + 1, s + ')')

        dfs(0, 0, '')
        return result