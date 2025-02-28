/*
1092. Shortest Common Supersequence 
    Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

    A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

    Example :
    Input: str1 = "abac", str2 = "cab"
    Output: "cabac"
    Explanation: 
    str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
    str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
    The answer provided is the shortest such string that satisfies these properties.
*/

#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            int m = str1.length();
            int n = str2.length();
    
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            
            for ( int i = 1; i <= m; i++){
                for (int j = 1; j <= n; j++){
                    if (str1[i - 1] == str2[j - 1]){
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            string res;
            int i = m, j = n;
            while (i > 0 || j > 0){
                if (i > 0 && j > 0 && str1[i - 1] == str2[j - 1]){
                    res += str1[i - 1];
                    i--;
                    j--;
                } else if (j > 0 && (i == 0 || dp[i][j - 1] >= dp[i - 1][j])){
                    res += str2[j - 1];
                    j--;
                } else {
                    res += str1[i - 1];
                    i--;
                }
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };