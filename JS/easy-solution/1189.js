/**
1189. Maximum Number of Balloons
    Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
    You can use each character in text at most once. Return the maximum number of instances that can be formed.

    Example :
    Input: text = "nlaebolko"
    Output: 1
 */



/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function(text) {
    const freq = Array(26).fill(0);
    for (const c of text) {
        freq[c.charCodeAt(0) - 97]++;
    }
    const countB = freq['b'.charCodeAt(0) - 97];
    const countA = freq['a'.charCodeAt(0) - 97];
    const countL = Math.floor(freq['l'.charCodeAt(0) - 97] / 2);
    const countO = Math.floor(freq['o'.charCodeAt(0) - 97] / 2);
    const countN = freq['n'.charCodeAt(0) - 97];
    return Math.min(countB, countA, countL, countO, countN);
};