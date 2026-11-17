/**
2911. Minimum Changes to Make K Semi-palindromes
    Given a string s and an integer k, partition s into k substrings such that the letter changes needed to make each substring a semi-palindrome are minimized.
    Return the minimum number of letter changes required.
    A semi-palindrome is a special type of string that can be divided into palindromes based on a repeating pattern. To check if a string is a semi-palindrome:​
    Choose a positive divisor d of the string's length. d can range from 1 up to, but not including, the string's length. For a string of length 1, it does not have a valid divisor as per this definition, since the only divisor is its length, which is not allowed.
    For a given divisor d, divide the string into groups where each group contains characters from the string that follow a repeating pattern of length d. Specifically, the first group consists of characters at positions 1, 1 + d, 1 + 2d, and so on; the second group includes characters at positions 2, 2 + d, 2 + 2d, etc.
    The string is considered a semi-palindrome if each of these groups forms a palindrome.
    Consider the string "abcabc":

    The length of "abcabc" is 6. Valid divisors are 1, 2, and 3.
    For d = 1: The entire string "abcabc" forms one group. Not a palindrome.
    For d = 2:
    Group 1 (positions 1, 3, 5): "acb"
    Group 2 (positions 2, 4, 6): "bac"
    Neither group forms a palindrome.
    For d = 3:
    Group 1 (positions 1, 4): "aa"
    Group 2 (positions 2, 5): "bb"
    Group 3 (positions 3, 6): "cc"
    All groups form palindromes. Therefore, "abcabc" is a semi-palindrome.
    
    Example :
    Input: s = "abcac", k = 2
    Output: 1
    Explanation: Divide s into "ab" and "cac". "cac" is already semi-palindrome. Change "ab" to "aa", it becomes semi-palindrome with d = 1.
 */


/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var minimumChanges = function(s, k) {
    const n = s.length;
    const INF = Infinity;

    const divisors = Array.from(
        { length: n + 1 }, () => []
    );

    for (let d = 1; d <= n; d++) {
        for (let v = 1; v < d; v++) {
            if (d % v === 0) {
                divisors[d].push(v);
            }
        }
    }

    const cost = Array.from(
        { length: n + 1 },
        () => Array(n + 1).fill(INF)
    );

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const L = j - i + 1;
            let best = INF;

            for (const d of divisors[L]) {
                let changes = 0;

                for (let start = i; start < i + d; start++) {
                    let l = start;
                    let r = start +
                        Math.floor((j - start) / d) * d;

                    while (l < r) {
                        if (s[l] !== s[r]) {
                            changes++;
                        }

                        l += d;
                        r -= d;
                    }
                }

                best = Math.min(best, changes);
            }

            cost[i][j] = best;
        }
    }

    const dp = Array.from(
        { length: k + 1 },
        () => Array(n + 1).fill(INF)
    );

    dp[0][0] = 0;

    for (let t = 1; t <= k; t++) {
        for (let i = t; i <= n; i++) {
            for (let j = t - 1; j < i; j++) {
                if (dp[t - 1][j] < INF &&
                    cost[j][i - 1] < INF) {

                    dp[t][i] = Math.min(
                        dp[t][i],
                        dp[t - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }
    }

    return dp[k][n];
};