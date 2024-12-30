"""
2466. Count Ways to Build Good Strings
    Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:
    Append the character '0' zero times.
    Append the character '1' one times.
    This can be performed any number of times.
    A good string is a string constructed by the above process having a length between low and high (inclusive).
    Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

    Example :
    Input: low = 3, high = 3, zero = 1, one = 1
    Output: 8
    Explanation: 
    One possible valid good string is "011". 
    It can be constructed as follows: "" -> "0" -> "01" -> "011". 
    All binary strings from "000" to "111" are good strings in this example.
"""


class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        MOD = 10 ** 9 + 7
        
        if zero > one:
            return self.countGoodStrings(low, high, one, zero)

        dp = [0] * (high + 1)
        dp[0] = 1
        res = 0

        for i in range(1, high + 1):
            if i >= zero:
                dp[i] = (dp[i] + dp[i - zero]) % MOD
            if i >= one:
                dp[i] = (dp[i] + dp[i - one]) % MOD
            if i >= low:
                res = (res + dp[i]) % MOD

        return res