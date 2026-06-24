/**
3699. Number of ZigZag Arrays I
    You are given three integers n, l, and r.
    A ZigZag array of length n is defined as follows:
    Each element lies in the range [l, r].
    No two adjacent elements are equal.
    No three consecutive elements form a strictly increasing or strictly decreasing sequence.
    Return the total number of valid ZigZag arrays.
    Since the answer may be large, return it modulo 109 + 7.
    A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).
    A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

    Example :
    Input: n = 3, l = 4, r = 5
    Output: 2
    Explanation:
    There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

    [4, 5, 4]
    [5, 4, 5]
 */



class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1000000007;
        int m = r - l + 1;
        vector<long long> dp(m, 1);
        for (int i = 2; i <= n; i++) {
            vector<long long> pref(m);
            pref[0] = dp[0];
            for (int j = 1; j < m; j++) {
                pref[j] = (pref[j - 1] + dp[j]) % MOD;
            }
            vector<long long> newDp(m, 0);
            if (i % 2 == 0) {
                for (int j = 1; j < m; j++) {
                    newDp[j] = pref[j - 1];
                }
            } else {
                long long total = pref[m - 1];
                for (int j = 0; j < m - 1; j++) {
                    newDp[j] = (total - pref[j] + MOD) % MOD;
                }
            }
            dp = newDp;
        }
        long long ans = 0;
        for (long long x : dp) {
            ans = (ans + x) % MOD;
        }
        return ans * 2 % MOD;
    }
};