"""
1320. Minimum Distance to Type a Word Using Two Fingers
    You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate.
    For example, the letter 'A' is located at coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1).
    Given the string word, return the minimum total distance to type such string using only two fingers.
    The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.
    Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.

    Example :
    Input: word = "CAKE"
    Output: 3
    Explanation: Using two fingers, one optimal way to type "CAKE" is: 
    Finger 1 on letter 'C' -> cost = 0 
    Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
    Finger 2 on letter 'K' -> cost = 0 
    Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
    Total distance = 3
"""


class Solution:
    def minimumDistance(self, word: str) -> int:
        def dist(a, b):
            if a == 26 or b == 26:
                return 0
            return abs(a // 6 - b // 6) + abs(a % 6 - b % 6)

        A = ord('A')
        index = [ord(c) - A for c in word]
        dp = [float('inf')] * 27
        dp[26] = 0 

        prev = index[0]

        for i in range(1, len(index)):
            cur = index[i]
            new_dp = [float('inf')] * 27

            for free in range(27):
                if dp[free] == float('inf'):
                    continue
                new_dp[free] = min(new_dp[free], dp[free] + dist(prev, cur))
                new_dp[prev] = min(new_dp[prev], dp[free] + dist(free, cur))

            dp = new_dp
            prev = cur

        return min(dp)