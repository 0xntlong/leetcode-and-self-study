/**
940. Distinct Subsequences II
    Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.
    A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.
    Example :
    Input: s = "abc"
    Output: 7
    Explanation: The 7 d
 */



/**
 * @param {string} s
 * @return {number}
 */
var distinctSubseqII = function(s) {
    const MOD = 1000000007;

    const count = new Array(26).fill(0);
    let sum = 0;

    for (const c of s) {
        const total = (1 + sum) % MOD;
        const idx = c.charCodeAt(0) - 97;

        sum = (sum + total - count[idx] + MOD) % MOD;
        count[idx] = total;
    }

    return sum;
};