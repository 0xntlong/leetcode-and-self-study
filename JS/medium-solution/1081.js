/**
1081. Smallest Subsequence of Distinct Characters
    Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

    Example :
    Input: s = "bcabc"
    Output: "abc"
 */



/**
 * @param {string} s
 * @return {string}
 */
var smallestSubsequence = function(s) {
    const freq = new Map();
    const visited = new Set();
    const stack = [];

    for (const c of s) {
        freq.set(c, (freq.get(c) || 0) + 1);
    }

    for (const c of s) {
        freq.set(c, freq.get(c) - 1);

        if (visited.has(c)) {
            continue;
        }

        while (
            stack.length > 0 &&
            stack[stack.length - 1] > c &&
            freq.get(stack[stack.length - 1]) > 0
        ) {
            visited.delete(stack.pop());
        }

        stack.push(c);
        visited.add(c);
    }

    return stack.join("");
};