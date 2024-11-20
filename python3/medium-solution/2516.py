"""
2516. Take K of Each Character From Left and Right
    You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
    Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

    Example :
    Input: s = "aabaaaacaabc", k = 2
    Output: 8
    Explanation: 
    Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
    Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
    A total of 3 + 5 = 8 minutes is needed.
    It can be proven that 8 is the minimum number of minutes needed.
"""


class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        n = len(s)
        l, r = 0, 0
        ans = n
        a, b, c = 0, 0, 0
        countA, countB, countC = 0, 0, 0
        for ch in s:
            if ch == 'a':
                countA += 1
            if ch == 'b':
                countB += 1
            if ch == 'c':
                countC += 1
        if countA < k or countB < k or countC < k:
            return -1
        while r < n :
            if s[r] == 'a':
                a += 1
            if s[r] == 'b':
                b += 1
            if s[r] == 'c':
                c +=  1
            r += 1
            while a > countA - k or b > countB - k or c > countC - k:
                if s[l] == 'a':
                    a -= 1
                if s[l] == 'b':
                    b -= 1
                if s[l] == 'c':
                    c -= 1
                l += 1
            ans = min(ans, n - (r - l))
        return ans