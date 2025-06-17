"""
3405. Count the Number of Arrays with K Matching Adjacent Elements
    You are given three integers n, m, k. A good array arr of size n is defined as follows:
    Each element in arr is in the inclusive range [1, m].
    Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
    Return the number of good arrays that can be formed.
    Since the answer may be very large, return it modulo 109 + 7.

    Example :
    Input: n = 3, m = 2, k = 1
    Output: 4
    Explanation:
    There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2, 2, 1].
    Hence, the answer is 4.
"""

class Solution:
    mod = 10**9 + 7
    MAX = 10**5 + 10
    factorial= [1] + [0] * MAX
    Inv = [1] + [0] * MAX

    for i in range(1, MAX):
        factorial[i] = factorial[i - 1] * i % mod
        Inv[i] = pow(factorial[i], mod - 2, mod)

    def comb(self, m : int, n : int) -> int:
        return self.factorial[m] * self.Inv[n] * self.Inv[m - n] % self.mod

    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        return self.comb(n - 1, k) * m * pow(m - 1, n - k - 1, self.mod) % self.mod