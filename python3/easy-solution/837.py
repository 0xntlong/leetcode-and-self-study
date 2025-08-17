"""
837. New 21 Game
    Alice plays the following game, loosely based on the card game "21".
    Alice starts with 0 points and draws numbers while she has less than k points. During each draw, she gains an integer number of points randomly from the range [1, maxPts], where maxPts is an integer. Each draw is independent and the outcomes have equal probabilities.
    Alice stops drawing numbers when she gets k or more points.
    Return the probability that Alice has n or fewer points.
    Answers within 10-5 of the actual answer are considered accepted.

    Example :
    Input: n = 10, k = 1, maxPts = 10
    Output: 1.00000
    Explanation: Alice gets a single card, then stops.
"""



class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        if k == 0 or n >= k - 1 + maxPts:
            return 1.0
        if n < k:
            return 0.0
        dp = [0.0] * (n + 1)
        
        for i in range(1, n + 1):
            dp[i] = 1.0
        right = min(n, k + maxPts - 1)
        window = sum(dp[k: right + 1])

        for i in range(k - 1, -1, -1):
            dp[i] = window / maxPts
            window += dp[i]
            if i + maxPts <= n:
                window -= dp[i + maxPts]

        return dp[0]