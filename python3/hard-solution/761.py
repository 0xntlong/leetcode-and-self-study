"""
761. Special Binary String
    Special binary strings are binary strings with the following two properties:
    The number of 0's is equal to the number of 1's.
    Every prefix of the binary string has at least as many 1's as 0's.
    You are given a special binary string s.
    A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.
    Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.

    Example:
    Input: s = "11011000"
    Output: "11100100"
    Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
    This is the lexicographically largest string possible after some number of swaps.
"""



class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        res = []
        cnt = 0
        idx = 0
        for i in range(len(s)):
            if s[i] == "1":
                cnt += 1
            else:
                cnt -= 1
            if cnt == 0:
                res.append("1" + self.makeLargestSpecial(s[idx + 1 : i]) + "0")
                idx = i + 1
        res.sort(reverse = True)
        return "".join(res)