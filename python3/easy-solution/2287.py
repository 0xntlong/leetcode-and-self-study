"""
2287. Rearrange Characters to Make Target String
    You are given two 0-indexed strings s and target. You can take some letters from s and rearrange them to form new strings.
    Return the maximum number of copies of target that can be formed by taking letters from s and rearranging them.

    Example :
    Input: s = "ilovecodingonleetcode", target = "code"
    Output: 2
    Explanation:
    For the first copy of "code", take the letters at indices 4, 5, 6, and 7.
    For the second copy of "code", take the letters at indices 17, 18, 19, and 20.
    The strings that are formed are "ecod" and "code" which can both be rearranged into "code".
    We can make at most two copies of "code", so we return 2.
"""


class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        freq_s = [0] * 26
        freq_t = [0] * 26
        for c in s:
            freq_s[ord(c) - ord('a')] += 1

        for c in target:
            freq_t[ord(c) - ord('a')] += 1
        
        min_count = float('inf')
        for i in range(26):
            if freq_t[i] > 0:
                min_count = min(min_count, freq_s[i] // freq_t[i])

        return min_count