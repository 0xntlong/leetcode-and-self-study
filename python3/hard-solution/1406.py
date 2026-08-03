"""
1406. Stone Game III
    Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
    Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.
    The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially
    The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.
    Assume Alice and Bob play optimally.
    Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

    Example :
    Input: stoneValue = [1,2,3,7]
    Output: "Bob"
    Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.

"""


from typing import List

class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        s1, s2, s3 = 0, 0, 0
        total = 0

        for value in reversed(stoneValue):
            total += value
            s1, s2, s3 = total - min(s1, s2, s3), s1, s2
            
        bob = total - s1
        if s1 > bob:
            return "Alice"
        if s1 < bob:
            return "Bob"
        if s1 == bob:
            return "Tie"