/**
2131. Longest Palindrome by Concatenating Two Letter Words
    You are given an array of strings words. Each element of words consists of two lowercase English letters.
    Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
    Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
    A palindrome is a string that reads the same forward and backward.
    Example :
    Input: words = ["lc","cl","gg"]
    Output: 6
    Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
    Note that "clgglc" is another longest palindrome that can be created.
 */


/**
 * @param {string[]} words
 * @return {number}
 */
var longestPalindrome = function(words) {
    const freq = Array.from({length: 26}, () => Array(26).fill(0));
    for (const w of words){
        const a = w.charCodeAt(0) - 97;
        const b = w.charCodeAt(1) - 97;
        freq[a][b]++;
    }
    let total = 0;
    let center = false;
    for (let i = 0; i < 26; i++){
        total += Math.floor(freq[i][i] / 2) * 4;
        if (freq[i][i] % 2 === 1){
            center = true;
        }
        for (let j = i + 1; j < 26; j++){
            const pairs = Math.min(freq[i][j], freq[j][i]);
            total += pairs * 4;
        }
    }
    if (center){
        total += 2;
    }
    return total;
};