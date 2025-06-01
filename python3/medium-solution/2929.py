"""
2929. Distribute Candies Among Children II
    You are given two positive integers n and limit.
    Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.

    Example :
    Input: n = 5, limit = 2
    Output: 3
    Explanation: There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).
"""


class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        def C(n):
            if n < 0:
                return 0
            else:
                return (n + 2) * (n + 1) // 2
        return ( C(n) 
                - 3 * C(n - limit - 1)
                + 3 * C(n - 2 * (limit + 1))
                - C(n - 3 * (limit + 1))
        )