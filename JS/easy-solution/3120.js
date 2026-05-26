/**
3120. Count the Number of Special Characters I
    You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
    Return the number of special letters in word.
    Example :
    Input: word = "aaAbcBC"
    Output: 3
    Explanation:
    The special characters in word are 'a', 'b', and 'c'.
 */



/**
 * @param {string} word
 * @return {number}
 */
var numberOfSpecialChars = function(word) {
    const lower = new Set();
    const upper = new Set();
    for (const c of word) {
        if (c >= 'a' && c <= 'z') {
            lower.add(c);
        } else {
            upper.add(c.toLowerCase());
        }
    }
    let ans = 0;
    for (const c of lower) {
        if (upper.has(c)) {
            ans++;
        }
    }
    return ans;
};