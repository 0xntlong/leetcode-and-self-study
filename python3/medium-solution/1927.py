"""
1927. Sum Game
    Alice and Bob take turns playing a game, with Alice starting first.
    You are given a string num of even length consisting of digits and '?' characters. On each turn, a player will do the following if there is still at least one '?' in num:
    Choose an index i where num[i] == '?'.
    Replace num[i] with any digit between '0' and '9'.
    The game ends when there are no more '?' characters in num.
    For Bob to win, the sum of the digits in the first half of num must be equal to the sum of the digits in the second half. For Alice to win, the sums must not be equal.
    For example, if the game ended with num = "243801", then Bob wins because 2+4+3 = 8+0+1. If the game ended with num = "243803", then Alice wins because 2+4+3 != 8+0+3.
    Assuming Alice and Bob play optimally, return true if Alice will win and false if Bob will win.

    Example :
    Input: num = "5023"
    Output: false
    Explanation: There are no moves to be made.
    The sum of the first half is equal to the sum of the second half: 5 + 0 = 2 + 3.
"""

class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num) // 2

        nums = [
            9 if ch == '?' else 2 * int(ch)
            for ch in num
        ]

        return sum(nums[:n]) != sum(nums[n:])