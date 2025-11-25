"""
1015. Smallest Integer Divisible by K
    Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.
    Return the length of n. If there is no such n, return -1.
    Note: n may not fit in a 64-bit signed integer.

    Example :
    Input: k = 1
    Output: 1
    Explanation: The smallest answer is n = 1, which has length 1.

"""



class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k % 2 == 0 or k % 5 == 0:
            return -1
        remain = 0
        l = 0
        for i in range(1, k + 1):
            remain = (remain * 10 + 1) % k
            l += 1
            if remain == 0:
                return l
        return l