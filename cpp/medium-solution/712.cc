/**
712. Minimum ASCII Delete Sum for Two Strings
    Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.
    Example :
    Input: s1 = "sea", s2 = "eat"
    Output: 231
    Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
    Deleting "t" from "eat" adds 116 to the sum.
    At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
 */



class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> dp(n2 + 1, 0);
        for (int i = 1; i <= n1; i++){
            vector<int> dp_new = dp;
            for (int j = 1; j <= n2; j++){
                if (s1[i - 1] == s2[j - 1]){
                    dp_new[j] = s2[j - 1] + dp[j - 1];
                } else {
                    dp_new[j] = max(dp[j], dp_new[j - 1]);
                }
            }
            dp = dp_new;
        }
        int total = 0;
        for (char c : s1)
            total += c;
        for (char c : s2)
            total += c;
        return total - 2 * dp[n2];
    }
};