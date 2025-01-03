"""
2347. Best Poker Hand
    You are given an integer array ranks and a character array suits. You have 5 cards where the ith card has a rank of ranks[i] and a suit of suits[i].
    The following are the types of poker hands you can make from best to worst:
    "Flush": Five cards of the same suit.
    "Three of a Kind": Three cards of the same rank.
    "Pair": Two cards of the same rank.
    "High Card": Any single card.
    Return a string representing the best type of poker hand you can make with the given cards.
    Note that the return values are case-sensitive.

    Example:
    Input: ranks = [13,2,3,1,9], suits = ["a","a","a","a","a"]
    Output: "Flush"
    Explanation: The hand with all the cards consists of 5 cards with the same suit, so we have a "Flush".
"""

from collections import Counter
from typing import List
class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        if len(set(suits)) == 1:
            return "Flush"
        count = Counter(ranks)
        if max(count.values()) >= 3:
            return "Three of a Kind"
        elif max(count.values()) == 2:
            return "Pair"
        else:
            return "High Card"