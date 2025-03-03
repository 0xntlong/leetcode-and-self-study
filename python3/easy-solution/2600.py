"""
2600. K Items Maximum Sum
    There is a bag that consists of items, each item has a number 1, 0, or -1 written on it.
    You are given four non-negative integers numOnes, numZeros, numNegOnes, and k.
    The bag initially contains:
    numOnes items with 1s written on them.
    numZeroes items with 0s written on them.
    numNegOnes items with -1s written on them.
    We want to pick exactly k items among the available items. Return the maximum possible sum of numbers written on the items.

    Example :
    Input: numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
    Output: 2
    Explanation: We have a bag of items with numbers written on them {1, 1, 1, 0, 0}. We take 2 items with 1 written on them and get a sum in a total of 2.
    It can be proven that 2 is the maximum possible sum.
"""


class Solution:
    def kItemsWithMaximumSum(self, numOnes: int, numZeros: int, numNegOnes: int, k: int) -> int:
        one = min(numOnes, k)
        k -= one
        zero = min(numZeros, k)
        k -= zero
        neg = k
        return one - neg