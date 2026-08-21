"""
3116. Kth Smallest Amount With Single Denomination Combination
    You are given an integer array coins representing coins of different denominations and an integer k.
    You have an infinite number of coins of each denomination. However, you are not allowed to combine coins of different denominations.
    Return the kth smallest amount that can be made using these coins.

    Example :
    Input: coins = [3,6,9], k = 3
    Output: 9
    Explanation: The given coins can make the following amounts:
    Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.
    Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.
    Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.
    All of the coins combined produce: 3, 6, 9, 12, 15, etc.
"""

from math import gcd
from typing import List

class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        coins.sort()

        new_coins = []

        for x in coins:
            keep = True

            for y in new_coins:
                if x % y == 0:
                    keep = False
                    break

            if keep:
                new_coins.append(x)

        coins = new_coins

        n = len(coins)
        m = 1 << n

        lcm = [1] * m

        left = k
        right = coins[0] * k + 1

        for mask in range(1, m):
            prev_mask = mask & (mask - 1)

            lowest_bit = mask & -mask
            i = lowest_bit.bit_length() - 1

            temp = lcm[prev_mask] // gcd(
                lcm[prev_mask],
                coins[i]
            )

            if temp <= right // coins[i]:
                lcm[mask] = temp * coins[i]
            else:
                lcm[mask] = right + 1

        def get(x: int) -> int:
            count = 0

            for mask in range(1, m):
                if lcm[mask] > x:
                    continue

                if mask.bit_count() % 2 == 1:
                    count += x // lcm[mask]
                else:
                    count -= x // lcm[mask]

            return count

        while left < right:
            mid = (left + right) // 2

            if get(mid) >= k:
                right = mid
            else:
                left = mid + 1

        return left
