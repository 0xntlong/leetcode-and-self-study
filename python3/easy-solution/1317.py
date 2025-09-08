"""
1317. Convert Integer to the Sum of Two No-Zero Integers
    No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.
    Given an integer n, return a list of two integers [a, b] where:
    a and b are No-Zero integers.
    a + b = n
    The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

    Example :
    Input: n = 2
    Output: [1,1]
    Explanation: Let a = 1 and b = 1.
    Both a and b are no-zero integers, and a + b = 2 = n.
"""


from typing import List

class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        def check(n):
            while n:
                temp = n % 10
                if temp == 0:
                    return False
                n //= 10
            return True
        for j in range(1, n):
            i = n - j
            if check(i) and check(j):
                return [i, j]