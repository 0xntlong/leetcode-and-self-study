"""
3336. Find the Number of Subsequences With Equal GCD
    You are given an integer array nums.
    Your task is to find the number of pairs of non-empty subsequences (seq1, seq2) of nums that satisfy the following conditions:
    The subsequences seq1 and seq2 are disjoint, meaning no index of nums is common between them.
    The GCD of the elements of seq1 is equal to the GCD of the elements of seq2.
    Return the total number of such pairs.
    Since the answer may be very large, return it modulo 109 + 7.

    Example:
    Input: nums = [1,2,3,4]
    Output: 10
    Explanation:
    The subsequence pairs which have the GCD of their elements equal to 1 are:
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])
    ([1, 2, 3, 4], [1, 2, 3, 4])

"""

from typing import List
import math
class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        MOD = 1000000007
        m = max(nums)
        dp = [[0] * (m + 1) for _ in range(m + 1)]
        dp[0][0] = 1
        
        for num in nums:
            ndp = [[0] * (m + 1) for _ in range(m + 1)]
            
            for j in range(m + 1):
                divisor1 = math.gcd(j, num)
                for k in range(m + 1):
                    val = dp[j][k]
                    if val == 0:
                        continue
                    
                    divisor2 = math.gcd(k, num)
                    ndp[j][k] = (ndp[j][k] + val) % MOD
                    ndp[divisor1][k] = (ndp[divisor1][k] + val) % MOD
                    ndp[j][divisor2] = (ndp[j][divisor2] + val) % MOD
                    
            dp = ndp
        
        ans = 0
        for j in range(1, m + 1):
            ans = (ans + dp[j][j]) % MOD
        
        return ans