"""
2410. Maximum Matching of Players With Trainers
    You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.

    The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.

    Return the maximum number of matchings between players and trainers that satisfy these conditions.

    

    Example :
    Input: players = [4,7,9], trainers = [8,2,5,8]
    Output: 2
    Explanation:
    One of the ways we can form two matchings is as follows:
    - players[0] can be matched with trainers[0] since 4 <= 8.
    - players[1] can be matched with trainers[3] since 7 <= 8.
    It can be proven that 2 is the maximum number of matchings that can be formed.
"""

from typing import List

class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        n = len(players)
        m = len(trainers)
        match = 0
        i = j = 0
        while i < n and j < m:
            if players[i] <= trainers[j]:
                match += 1
                i += 1
            j += 1
        return match