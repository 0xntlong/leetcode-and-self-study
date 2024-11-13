"""
1652. Defuse the Bomp
    You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.
    To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.
    If k > 0, replace the ith number with the sum of the next k numbers.
    If k < 0, replace the ith number with the sum of the previous k numbers.
    If k == 0, replace the ith number with 0.
    As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].
    Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

    Example :
    Input: code = [5,7,1,4], k = 3
    Output: [12,10,16,13]
    Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
"""

from typing import List

class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        ans = [0] * n
        if k == 0:
            return ans
        for i in range(n):
            total = 0
            if k > 0:
                for j in range(1, k + 1):
                    total += code[(i + j) % n]
            else :
                for j in range(1, -k + 1):
                    total += code[(i - j + n) % n]
            ans[i] = total
        return ans