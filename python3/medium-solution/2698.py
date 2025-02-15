"""
2698. Find the Punishment Number of an Integer
    Given a positive integer n, return the punishment number of n.
    The punishment number of n is defined as the sum of the squares of all integers i such that:
    1 <= i <= n
    The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.

    Example :
    Input: n = 10
    Output: 182
    Explanation: There are exactly 3 integers i in the range [1, 10] that satisfy the conditions in the statement:
    - 1 since 1 * 1 = 1
    - 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to 8 + 1 == 9.
    - 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum equal to 10 + 0 == 10.
    Hence, the punishment number of 10 is 1 + 81 + 100 = 182
"""


class Solution:
    def punishmentNumber(self, n: int) -> int:
        
        def partition(num: str, target: int) -> bool:
            if not num:
                return target == 0

            for i in range(1, len(num) + 1):
                part = int(num[:i])
                if part > target:
                    break
                if partition(num[i:], target - part):
                    return True
            return False
        
        total = 0
        
        for i in range(1, n + 1):
            square = i * i
            if partition(str(square), i):
                total += square
        
        return total
