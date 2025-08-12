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



/**
 * @param {number} n
 * @param {number} x
 * @return {number}
 */
var numberOfWays = function(n, x) {
    const mod = 1e9 + 7;
    const dp = new Array(n + 1).fill(0);
    dp[0] = 1;
    for (let base = 1; ;base++){
        let v = 1;
        for (let t = 0; t < x; t++){
            v *= base;
            if (v > n)
                break;
        }
        if (v > n)
            break;
        for (let s = n; s >= v; s--){
            dp[s] += dp[s - v];
            if (dp[s] >= mod)
                dp[s] -= mod;
        }
    }
    return dp[n];
};