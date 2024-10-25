"""
1399. Count Largest Group
    You are given an integer n.
    Each number from 1 to n is grouped according to the sum of its digits.
    Return the number of groups that have the largest size.

    Example :
    Input: n = 13
    Output: 4
    Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
    [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
    There are 4 groups with largest size.
"""

class Solution:
    def countLargestGroup(self, n: int) -> int:
        def sumDigit(x):
            return sum(int(digit) for digit in str(x))
        Dict = {}
        for i in range(1, n + 1):
            total = sumDigit(i)
            if total not in Dict:
                Dict[total] = 0
            Dict[total] += 1
        max_range = max(Dict.values())
        Largest = sum(1 for x in Dict.values() if x == max_range)
        return Largest
