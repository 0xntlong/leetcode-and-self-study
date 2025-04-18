"""
38. Count and Say
    The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
    countAndSay(1) = "1"
    countAndSay(n) is the run-length encoding of countAndSay(n - 1).
    Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".
    Given a positive integer n, return the nth element of the count-and-say sequence.

    Example 1:
    Input: n = 4
    Output: "1211"
    Explanation:
    countAndSay(1) = "1"
    countAndSay(2) = RLE of "1" = "11"
    countAndSay(3) = RLE of "11" = "21"
    countAndSay(4) = RLE of "21" = "1211"
"""


class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'

        def str_sequence(sequence):
            ans = []
            for freq, digit in sequence:
                ans.append(str(freq))
                ans.append(digit)
            return ''.join(ans)
        sequence = [(1, '1')]
        s1 = str_sequence(sequence)
        for i in range(3, n + 1):
            length = len(s1)
            c = s1[0]
            sequence = [(1, c)]
            for i in range(1, length):
                if s1[i] == c:
                    sequence[-1] = (sequence[-1][0] + 1, c)
                else:
                    sequence.append((1, s1[i]))
                    c = s1[i]
            s1 = str_sequence(sequence)
        return s1