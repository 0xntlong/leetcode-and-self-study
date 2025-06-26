/**
2311. Longest Binary Subsequence Less Than or Equal to K
    You are given a binary string s and a positive integer k.
    Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.
    Note:
    The subsequence can contain leading zeroes.
    The empty string is considered to be equal to 0.
    A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

    Example :

    Input: s = "1001010", k = 5
    Output: 5
    Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
    Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
    The length of this subsequence is 5, so 5 is returned.
 */


/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var longestSubsequence = function(s, k) {
    let sum = 0;
    let cnt = 0;
    const bits = Math.floor(Math.log2(k)) + 1;
    for (let i = 0; i < s.length; i++){
        const c = s[s.length - 1 - i];
        if (c === '1'){
            if (i < bits && sum + (1 << i) <= k){
                sum += 1 << i;
                cnt++;
            }
        } else {
            cnt++;
        }
    }
    return cnt++;
};