"""
1563. Stone Game V
    There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
    In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row
    The game ends when there is only one stone remaining. Alice's score is initially zero.
    Return the maximum score that Alice can obtain.
    Example :
    Input: stoneValue = [6,2,3,4,5,5]
    Output: 18
    Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
    In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
    The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.
"""

from typing import List


class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)

        prefix = [0] * (n + 1)

        for i in range(1, n + 1):
            prefix[i] = prefix[i - 1] + stoneValue[i - 1]

        def search(left_bound: int, right_bound: int) -> int:
            total = prefix[right_bound + 1] - prefix[left_bound]
            start = left_bound

            left = left_bound
            right = right_bound

            while left < right:
                mid = left + (right - left) // 2
                left_sum = prefix[mid + 1] - prefix[start]

                if left_sum * 2 >= total:
                    right = mid
                else:
                    left = mid + 1

            return left

        dp = [[0] * n for _ in range(n)]
        left = [[0] * n for _ in range(n)]
        right = [[0] * n for _ in range(n)]

        for i in range(n):
            left[i][i] = stoneValue[i]
            right[i][i] = stoneValue[i]

        for length in range(1, n):
            for i in range(n - length):
                j = i + length

                k = search(i, j)

                total = prefix[j + 1] - prefix[i]
                left_half = prefix[k + 1] - prefix[i]

                if left_half * 2 == total:
                    dp[i][j] = max(
                        left[i][k],
                        right[k + 1][j]
                    )
                else:
                    left_best = 0 if k == i else left[i][k - 1]
                    right_best = 0 if k == j else right[k + 1][j]

                    dp[i][j] = max(
                        left_best,
                        right_best
                    )

                left[i][j] = max(
                    left[i][j - 1],
                    total + dp[i][j]
                )

                right[i][j] = max(
                    right[i + 1][j],
                    total + dp[i][j]
                )

        return dp[0][n - 1]