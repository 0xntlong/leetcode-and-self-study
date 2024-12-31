"""
2309. Greatest English Letter in Upper and Lower Case
    Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.
    An English letter b is greater than another letter a if b appears after a in the English alphabet.
    Example::
    Input: s = "lEeTcOdE"
    Output: "E"
    Explanation:
    The letter 'E' is the only letter to appear in both lower and upper case.
"""


class Solution:
    def greatestLetter(self, s: str) -> str:
        # freqLower = [0] * 26
        # freqUpper = [0] * 26
        # ans = ""
        # for c in s:
        #     if 'a' <= c <= 'z':
        #         idx = ord(c) - ord('a')
        #         freqLower[idx] += 1
        #     elif 'A' <= c <= 'Z':
        #         idx = ord(c) - ord('A')
        #         freqUpper[idx] += 1
        # for i in range(25, -1, -1):
        #     if freqUpper[i] > 0 and freqLower[i] > 0:
        #         ans = chr(i + ord('A'))
        #         break
        # return ans

        for i in range(25, -1, -1):
            lower = chr(i + ord('a'))
            upper = chr(i + ord('A'))
            if lower in s and upper in s:
                return upper
        return ''