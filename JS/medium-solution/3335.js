/**
3335. Total Characters in String After Transformations I
    You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:
    If the character is 'z', replace it with the string "ab".
    Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
    Return the length of the resulting string after exactly t transformations.
    Since the answer may be very large, return it modulo 109 + 7.

    Example :
    Input: s = "abcyy", t = 2
    Output: 7
    Explanation:
    First Transformation (t = 1):
    'a' becomes 'b'
    'b' becomes 'c'
    'c' becomes 'd'
    'y' becomes 'z'
    'y' becomes 'z'
    String after the first transformation: "bcdzz"
    Second Transformation (t = 2):
    'b' becomes 'c'
    'c' becomes 'd'
    'd' becomes 'e'
    'z' becomes "ab"
    'z' becomes "ab"
    String after the second transformation: "cdeabab"
    Final Length of the string: The string is "cdeabab", which has 7 characters.
 */

/**
 * @param {string} s
 * @param {number} t
 * @return {number}
 */
var lengthAfterTransformations = function(s, t) {
    const mod = 1e9 + 7;
    const freq = new Array(26).fill(0);
    for (let c of s){
        freq[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    for (let i = 0; i < t; i++){
        let lastAlphabet = freq[25];
        let f0 = freq[0];
        for (let j = 25; j > 0; j--){
            freq[j] = freq[j - 1];
        }
        freq[0] = lastAlphabet;
        f0 += lastAlphabet;
        if (f0 >= mod){
            f0 -= mod;
        } 
        freq[1] = f0;
    }
    let res = 0;
    for (let i of freq){
        res = (res + i) % mod;
    }
    return res;
};