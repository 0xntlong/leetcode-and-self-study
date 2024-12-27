/*
1014. Best Sightseeing Pair
    You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
    The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
    Return the maximum score of a pair of sightseeing spots.

    Example :
    Input: values = [8,1,5,2,6]
    Output: 11
    Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
*/

#include <vector>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // int n = values.size();
        // int score = 0, dp = 0;
        // for (int i = 0; i < n; i++){
        //     score = max(score, dp + values[i] - i);
        //     dp = max(dp, values[i] + i);
        // }
        // return score;
        
        int score = 0;
        int idx = values[0];
        for (int i = 1; i < values.size(); i++){
            idx--;
            int j = values[i];
            score = max(score, idx + j);
            idx = max(idx, j);
        }
        return score;
    }
};