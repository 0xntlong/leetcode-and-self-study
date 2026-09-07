/**
940. Distinct Subsequences II
    Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.
    A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.
    Example :
    Input: s = "abc"
    Output: 7
    Explanation: The 7 d
 */



class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> count(26, 0);
        long long sum = 0;

        for (char c : s) {
            long long total = (1 + sum) % MOD;
            int idx = c - 'a';

            sum = (sum + total - count[idx] + MOD) % MOD;
            count[idx] = total;
        }

        return (int)sum;
    }
};