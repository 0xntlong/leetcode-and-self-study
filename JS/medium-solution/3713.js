/**
3713. Longest Balanced Substring I
    You are given a string s consisting of lowercase English letters.
    A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
    Return the length of the longest balanced substring of s.

    Example:
    Input: s = "abbac"
    Output: 4
    Explanation:
    The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.
 */


/**
 * @param {string} s
 * @return {number}
 */
var longestBalanced = function(s) {
    const n = s.length;
    const a = new Array(n);
    for (let i = 0; i < n; i++) 
        a[i] = s.charCodeAt(i) - 97;

    let res = 0;

    for (let l = 0; l < n; l++) {
        if (n - l <= res)
            break;

        const freq = new Array(26).fill(0);
        let unique = 0, maxFreq = 0;

        for (let r = l; r < n; r++) {
            const idx = a[r];
            if (freq[idx] === 0) 
                unique++;
            freq[idx]++;
            if (freq[idx] > maxFreq) 
                maxFreq = freq[idx];

            const curr = r - l + 1;
            if (unique * maxFreq === curr) {
                if (curr > res) 
                    res = curr;
            }
        }
    }

    return res;
};