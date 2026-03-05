/*
1758. Minimum Changes To Make Alternating Binary String
    You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.
    The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.
    Return the minimum number of operations needed to make s alternating.

    Example:
    Input: s = "0100"
    Output: 1
    Explanation: If you change the last character to '1', s will be "0101", which is alternating.
*/



/**
 * @param {string} s
 * @return {number}
 */
var minOperations = function(s) {
    let diff = 0;
    for (let i = 0; i < s.length; i++) {
        const ex = (i % 2 === 0) ? '1' : '0';
        if (s[i] !== ex)
            diff++;
    }
    return Math.min(diff, s.length - diff);
};