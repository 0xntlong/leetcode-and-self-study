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



/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
var minimumDeleteSum = function(s1, s2) {
    let n1 = s1.length, n2 = s2.length;
    let dp = Array(n2 + 1).fill(0);

    for (let i = 1; i <= n1; i++) {
        let dp_new = [...dp];
        for (let j = 1; j <= n2; j++) {
            if (s1[i - 1] === s2[j - 1]) {
                dp_new[j] = s2.charCodeAt(j - 1) + dp[j - 1];
            } else {
                dp_new[j] = Math.max(dp[j], dp_new[j - 1]);
            }
        }
        dp = dp_new;
    }

    let total = 0;
    for (let c of s1) 
        total += c.charCodeAt(0);
    for (let c of s2) 
        total += c.charCodeAt(0);

    return total - 2 * dp[n2];
};