"""
3536. Maximum Product of Two Digits
    You are given a positive integer n.
    Return the maximum product of any two digits in n.
    Note: You may use the same digit twice if it appears more than once in n.


    Example :
    Input: n = 31
    Output: 3
    Explanation:

    The digits of n are [3, 1].
    The possible products of any two digits are: 3 * 1 = 3.
    The maximum product is 3.
"""



class Solution:
    def maxProduct(self, n: int) -> int:
        d1, d2 = sorted(str(n))[-2:]
        return int(d1) * int(d2)
        """
        max1, max2 = 0, 0
        while n > 0:
            n, i = divmod(n, 10)
            if i >= max1:
                max2 = max1
                max1 = i
            elif i >= max2:
                max2 = i
        return max1*max2
        """