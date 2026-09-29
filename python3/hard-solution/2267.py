"""
2267. Check if There Is a Valid Parentheses String Path
    A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
    It is ().
    It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
    It can be written as (A), where A is a valid parentheses string.
    You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:
    The path starts from the upper left cell (0, 0).
    The path ends at the bottom-right cell (m - 1, n - 1).
    The path only ever moves down or right.
    The resulting parentheses string formed by the path is valid.
    Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.

    Example :
    Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
    Output: true
    Explanation: The above diagram shows two possible paths that form valid parentheses strings.
    The first path shown results in the valid parentheses string "()(())".
    The second path shown results in the valid parentheses string "((()))".
    Note that there may be other valid parentheses string paths.
"""


from linecache import cache


class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        
        if (m + n - 1) % 2 == 1 or grid[0][0] == ')' or grid[m - 1][n - 1] == '(':
            return False
            
        @cache
        def dfs(i: int, j: int, k: int) -> bool:
            k += 1 if grid[i][j] == '(' else -1
            
            if k < 0 or k > m - i + n - j - 1:
                return False

            if i == m - 1 and j == n - 1:
                return k == 0
                
            res = False
            if i + 1 < m:
                res = res or dfs(i + 1, j, k)
            if not res and j + 1 < n:
                res = res or dfs(i, j + 1, k)
                
            return res

        return dfs(0, 0, 0)