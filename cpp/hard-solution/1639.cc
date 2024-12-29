/*
1639. Number of Ways to Form a Target String Given a Dictionary
    You are given a list of strings of the same length words and a string target.
    Your task is to form target using the given words under the following rules:
    target should be formed from left to right.
    To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
    Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
    Repeat the process until you form the string target.
    Notice that you can use multiple characters from the same string in words provided the conditions above are met.
    Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

    Example :
    Input: words = ["acca","bbbb","caca"], target = "aba"
    Output: 6
    Explanation: There are 6 ways to form target.
    "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
    "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
    "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
    "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
    "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
    "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int word_L = words[0].size();
        int target_L = target.size();
        
        vector<vector<int>> charFrequency(word_L, vector<int>(26, 0));
        for (const string& word : words){
            for (int idx = 0; idx < word_L; idx++){
                charFrequency[idx][word[idx] - 'a']++;
            }
        }
        vector<long long> dp(target_L + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < word_L; i++){
            for (int j = target_L - 1; j >= 0; j--){
                if (charFrequency[i][target[j] - 'a'] > 0){
                    dp[j + 1] += dp[j] * charFrequency[i][target[j] - 'a'];
                    dp[j + 1] %= MOD;
                }
            }
        }
        return dp[target_L];
    }
};