"""
1432. Max Difference You Can Get From Changing an Integer
    You are given an integer num. You will apply the following steps to num two separate times:
    Pick a digit x (0 <= x <= 9).
    Pick another digit y (0 <= y <= 9). Note y can be equal to x.
    Replace all the occurrences of x in the decimal representation of num by y.
    Let a and b be the two results from applying the operation to num independently.
    Return the max difference between a and b.
    Note that neither a nor b may have any leading zeros, and must not be 0.

    Example :
    Input: num = 555
    Output: 888
    Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
    The second time pick x = 5 and y = 1 and store the new integer in b.
    We have now a = 999 and b = 111 and max difference = 888
"""


class Solution:
    def maxDiff(self, num: int) -> int:
        ten = [1] * 10
        for i in range(1, 10):
            ten[i] = ten[i - 1] * 10
        value = next(i for i in ten if i > num) // 10

        a, b = -1, -1
        x, y = 0, 0

        c = 0 if num // value == 1 else 1

        while value >= 1:
            d = num // value
            num %= value
            if a == -1 and d != 9:
                a = d
                x += 9 * value
            elif d == a:
                x += 9 * value
            else: 
                x += d * value
            
            if b == -1 and d != 0 and d != 1:
                b = d
                y += c * value
            elif d == b:
                y += c * value
            else:
                y += d * value
            value //= 10
        return x - y