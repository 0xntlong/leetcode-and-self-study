"""
3335. Total Characters in String After Transformations I
    You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:
    If the character is 'z', replace it with the string "ab".
    Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
    Return the length of the resulting string after exactly t transformations.
    Since the answer may be very large, return it modulo 109 + 7.

    Example :
    Input: s = "abcyy", t = 2
    Output: 7
    Explanation:
    First Transformation (t = 1):
    'a' becomes 'b'
    'b' becomes 'c'
    'c' becomes 'd'
    'y' becomes 'z'
    'y' becomes 'z'
    String after the first transformation: "bcdzz"
    Second Transformation (t = 2):
    'b' becomes 'c'
    'c' becomes 'd'
    'd' becomes 'e'
    'z' becomes "ab"
    'z' becomes "ab"
    String after the second transformation: "cdeabab"
    Final Length of the string: The string is "cdeabab", which has 7 characters.
"""


class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        mod = 10**9 + 7
        freq = [0] * 26
        for c in s:
            freq[ord(c) - ord('a')] += 1
        for _ in range(t):
            alphabet = freq[25]
            f0 = freq[0]
            for i in range(25, 1, -1):
                freq[i] = freq[i - 1]
            freq[0] = alphabet
            f0 += alphabet
            if f0 >= mod:
                f0 -= mod
            freq[1] = f0
        return sum(freq) % mod