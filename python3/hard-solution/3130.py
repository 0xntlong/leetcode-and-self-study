"""
3130. Find All Possible Stable Binary Arrays II
    You are given 3 positive integers zero, one, and limit.
    A binary array arr is called stable if:
    The number of occurrences of 0 in arr is exactly zero.
    The number of occurrences of 1 in arr is exactly one.
    Each subarray of arr with a size greater than limit must contain both 0 and 1.
    Return the total number of stable binary arrays.
    Since the answer may be very large, return it modulo 109 + 7.

    Example:
    Input: zero = 1, one = 1, limit = 2
    Output: 2
    Explanation:
    The two possible stable binary arrays are [1,0] and [0,1].

"""


class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        mod = 10**9 + 7
        def comp(i):
            ways = [0] * (i + 1)
            prev = [0] * (i + 1)
            prev[0] = 1
            for k in range(1, i + 1):
                curr = [0] * (i + 1)
                pref = 0
                left = 0
                for j in range(1, i + 1):
                    pref = (pref + prev[j - 1]) % mod
                    if j - limit - 1 >= 0:
                        pref = (pref - prev[j - limit - 1]) % mod
                    curr[j] = pref
                ways[k] = curr[i]
                prev = curr
            return ways
        Zero = comp(zero)
        One = comp(one)
        ans = 0
        for a in range(1, zero + 1):
            if a <= one:
                ans = (ans + Zero[a] * One[a]) % mod
            if a - 1 >= 1 and a - 1 <= one:
                ans = (ans + Zero[a] * One[a - 1]) % mod

        for a in range(1, zero + 1):
            if a <= one:
                ans = (ans + Zero[a] * One[a]) % mod
            if a + 1 <= one:
                ans = (ans + Zero[a] * One[a + 1]) % mod

        return ans % mod