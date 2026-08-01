/**
486. Predict the Winner
    You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
    Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.
    Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

    Example :
    Input: nums = [1,5,2]
    Output: false
    Explanation: Initially, player 1 can choose between 1 and 2. 
    If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
    So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
    Hence, player 1 will never be the winner and you need to return false.

 */


#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);

        for (int left = n - 1; left >= 0; left--) {
            dp[left] = nums[left];

            for (int right = left + 1; right < n; right++) {
                dp[right] = max(
                    nums[left] - dp[right],
                    nums[right] - dp[right - 1]
                );
            }
        }

        return dp[n - 1] >= 0;
    }
};