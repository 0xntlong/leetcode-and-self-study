"""
1556. Thousand Separator
    Given an integer n, add a dot (".") as the thousands separator and return it in string format.
    
    Example 1:
    Input: n = 987
    Output: "987"
    
    Example 2:
    Input: n = 1234
    Output: "1.234"
"""

class Solution:
    def thousandSeparator(self, n: int) -> str:
        ans = []
        str_n = str(n)
        for i in range(len(str_n) -1, -1, -1):
            ans.append(str_n[i])
            if (len(str_n) - i) % 3 == 0 and i != 0:
                ans.append(".")
        return "".join(ans[::-1])