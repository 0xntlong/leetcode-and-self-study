/**
3121. Count the Number of Special Characters II
    You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.
    Return the number of special letters in word.
    
    Example:
    Input: word = "aaAbcBC"
    Output: 3
    Explanation:

    The special characters are 'a', 'b', and 'c'.
 */



/**
 * @param {string} word
 * @return {number}
 */
var numberOfSpecialChars = function(word) {
    let count = 0;
    for (let i = 0; i < 26; i++) {
        const w = String.fromCharCode(97 + i);
        const up = w.toUpperCase();
        const lastLower = word.lastIndexOf(w);
        const firstUpper = word.indexOf(up);
        if (lastLower !== -1 &&
            firstUpper !== -1 &&
            lastLower < firstUpper) {
            count++;
        }
    }
    return count;
};