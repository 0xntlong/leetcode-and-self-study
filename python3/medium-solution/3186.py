"""
3186. Maximum Total Damage With Spell Casting
    A magician has various spells.
    You are given an array power, where each element represents the damage of a spell. Multiple spells can have the same damage value.
    It is a known fact that if a magician decides to cast a spell with a damage of power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.
    Each spell can be cast only once.
    Return the maximum possible total damage that a magician can cast.

    Example :
    Input: power = [1,1,3,4]
    Output: 6
    Explanation:
    The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.
"""


from typing import List
from collections import Counter

class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        cnt = Counter(power)
        arr = sorted(list(set(power)))
        n = len(arr)
        if n == 1:
            return arr[0] * cnt[arr[0]]

        dp = [0] * (n + 1)
        dp[0] = 0
        dp[1] = arr[0] * cnt[arr[0]]
        
        if arr[1] - arr[0] > 2:
            dp[2] = dp[1] + arr[1] * cnt[arr[1]]
        else:
            dp[2] = max(dp[1], arr[1] * cnt[arr[1]])
        
        for i in range(3, n + 1):
            if arr[i - 1] - arr[i - 2] > 2 and arr[i - 1] - arr[i - 3] > 2:
                dp[i] = dp[i - 1] + arr[i - 1] * cnt[arr[i - 1]]
            elif arr[i - 1] - arr[i - 3] > 2 and arr[i - 1] - arr[i - 2] < 3:
                dp[i] = max(dp[i - 2] + arr[i - 1] * cnt[arr[i - 1]], dp[i - 1])
            elif arr[i - 1] - arr[i - 3] < 3 and arr[i -1] - arr[i - 2] < 3:
                dp[i] = max(dp[i - 3] + arr[i - 1] * cnt[arr[i - 1]], dp[i - 1])
        return dp[-1]