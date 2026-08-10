/**
1510. Stone Game IV
    Alice and Bob take turns playing a game, with Alice starting first.
    Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.
    Also, if a player cannot make a move, he/she loses the game.
    Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.
    Example :
    Input: n = 1
    Output: true
    Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
 */



class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};