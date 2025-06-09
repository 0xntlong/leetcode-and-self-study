"""
440. K-th Smallest in Lexicographical Order
    Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

    Example 1:
    Input: n = 13, k = 2
    Output: 10
    Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
"""



class Solution:
    def count(self, n: int, a: int, b: int) -> int:
        total = 0
        while a <= n:
            total += min(n + 1, b) - a
            a *= 10
            b *= 10
        return total

    def findKthNumber(self, n: int, k: int) -> int:
        res = 1
        k -= 1
        while k:
            steps = self.count(n, res, res + 1)
            if steps <= k:
                k -= steps
                res += 1
            else:
                res *= 10
                k -= 1
        return res