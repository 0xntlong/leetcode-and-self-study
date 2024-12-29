"""
2269. Find the K-Beaty of a Number
    The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:
    It has a length of k.
    It is a divisor of num.
    Given integers num and k, return the k-beauty of num.
    Note:
    Leading zeros are allowed.
    0 is not a divisor of any value.
    A substring is a contiguous sequence of characters in a string.

    Example :
    Input: num = 240, k = 2
    Output: 2
    Explanation: The following are the substrings of num of length k:
    - "24" from "240": 24 is a divisor of 240.
    - "40" from "240": 40 is a divisor of 240.
    Therefore, the k-beauty is 2.
"""

class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        res = 0
        numStr = str(num)
        n = len(numStr)
        for i in range(n - k + 1):
            subStr = numStr[i : i + k]
            divisor = int(subStr)
            if divisor != 0 and num % divisor == 0:
                res += 1
        return res 