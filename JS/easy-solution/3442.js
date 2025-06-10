/**
3442. Maximum Difference Between Even and Odd Frequency I
    You are given a string s consisting of lowercase English letters.
    Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:
    a1 has an odd frequency in the string.
    a2 has an even frequency in the string.
    Return this maximum difference.


    Example :
    Input: s = "aaaaabbc"
    Output: 3
    Explanation:
    The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
    The maximum difference is 5 - 2 = 3.
 */

/**
 * @param {string} s
 * @return {number}
 */
var maxDifference = function(s) {
    let odd = -1;
    let even = Infinity;
    let freq = new Array(26).fill(0);
    for (let c of s){
        freq[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    for (let f of freq){
        if (f % 2 !== 0){
            odd = Math.max(odd, f);
        } else if ( f !== 0){
            even = Math.min(even, f);
        }
    }
    return odd - even;
};