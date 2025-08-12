/**
2787. Ways to Express an Integer as Sum of Powers
    Given two positive integers n and x.
    Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.
    Since the result can be very large, return it modulo 109 + 7.
    For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

    Example 1:
    Input: n = 10, x = 2
    Output: 1
    Explanation: We can express n as the following: n = 32 + 12 = 10.
    It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.
 */



class Solution {
public:
    int numberOfWays(int n, int x) {
        const int mod = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (long long base = 1; ;base++){
            long long v = 1;
            for (int t = 0; t < x; t++){
                v *= base;
                if (v > n)
                    break;
            }
            if (v > n)
                break;
            for (int s = n; s >= (int)v; s--){
                dp[s] += dp[s - (int)v];
                if (dp[s] >= mod)
                    dp[s] -= mod;
            }
        }
        return dp[n];
    }
};