"""
1674. Minimum Moves to Make Array Complementary
    You are given an integer array nums of even length n and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.
    The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.
    Return the minimum number of moves required to make nums complementary.

    Example :
    Input: nums = [1,2,4,3], limit = 4
    Output: 1
    Explanation: In 1 move, you can change nums to [1,2,2,3] (underlined elements are changed).
    nums[0] + nums[3] = 1 + 3 = 4.
    nums[1] + nums[2] = 2 + 2 = 4.
    nums[2] + nums[1] = 2 + 2 = 4.
    nums[3] + nums[0] = 3 + 1 = 4.
    Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.
"""

from typing import List
class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        dp = [0] * (2 * limit + 2)
        for i in range(n // 2):
            mini = min(nums[i], nums[-1 - i])
            maxi = max(nums[i], nums[-1 - i])
            dp[2] += 2
            dp[mini + 1] -= 1
            dp[mini + maxi] -= 1
            dp[mini + maxi + 1] += 1
            dp[maxi + limit + 1] += 1
        res = n
        moves = 0
        for c in range(2, 2 * limit + 1):
            moves += dp[c]
            res = min(res, moves)
        return res