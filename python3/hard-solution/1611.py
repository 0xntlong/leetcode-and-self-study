"""
1611. Minimum One Bit Operations to Make Integers Zero
    Given an integer n, you must transform it into 0 using the following operations any number of times:
    Change the rightmost (0th) bit in the binary representation of n.
    Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.
    Return the minimum number of operations to transform n into 0.
    Example :
    Input: n = 3
    Output: 2
    Explanation: The binary representation of 3 is "11".
    "11" -> "01" with the 2nd operation since the 0th bit is 1.
    "01" -> "00" with the 1st operation.
"""


class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        res = 0
        if n <= 1:
            return n
        while n > 1:
            res = - res - (n ^ (n - 1))
            n &= n - 1
        return abs(res)
        """
        #APPROACH 2
        def op(n):
            if n <= 1:
                return n
            k = int(log2(n))
            return (1<<(k + 1)) - 1 - op(n^(1<<k))
        return op(n)
        """
        """
        APPROACH 3
        binary = bin(n)[2:]
                op = 0
                sign = 1
                for i in range(len(binary)):
                    bit = binary[i]
                    if bit == '1':
                        op += sign * (2 ** (len(binary) - i) - 1)
                        sign *= -1
                return op
        """