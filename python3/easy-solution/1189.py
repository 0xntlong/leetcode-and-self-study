"""
1189. Maximum Number of Balloons
    Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
    You can use each character in text at most once. Return the maximum number of instances that can be formed.

    Example :
    Input: text = "nlaebolko"
    Output: 1
"""



class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        freq = [0] * 26
        for c in text:
            freq[ord(c) - ord('a')] += 1
        count_b = freq[ord('b') - ord('a')]
        count_a = freq[ord('a') - ord('a')]
        count_l = freq[ord('l') - ord('a')] // 2
        count_o = freq[ord('o') - ord('a')] // 2
        count_n = freq[ord('n') - ord('a')]

        return min(
            count_b,
            count_a,
            count_l,
            count_o,
            count_n
        )