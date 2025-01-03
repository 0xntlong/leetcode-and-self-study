/*
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
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool flag = 0;
        for (int i = 0; i < 4; i++){
            if (suits[i] != suits[i + 1])
                flag = 1;
        }
        if (!flag)
            return "Flush";
        bool countRank = 0;
        for (int i = 0; i < 4; i++){
            int count = 1;
            for (int j = i + 1; j < 5; j++){
                if (ranks[i] == ranks[j]){
                    count++;
                }
                if (count == 3){
                    return "Three of a Kind";
                }
                if (count == 2){
                    countRank = 1;
                }
            }
        }
        if (countRank){
            return "Pair";
        }
        return "High Card";
    }
};