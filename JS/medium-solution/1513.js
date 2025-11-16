/**
1513. Number of Substrings With Only 1s
    Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.
    Example :
    Input: s = "0110111"
    Output: 9
    Explanation: There are 9 substring in total with only 1's characters.
    "1" -> 5 times.
    "11" -> 3 times.
    "111" -> 1 time.
 */




/**
 * @param {string} s
 * @return {number}
 */
var numSub = function(s) {
    const mod = 1_000_000_007;
    let total = 0;
    s.split("0").filter(block => {
        const length = block.length;
        if(length) {
            total += (length * (length + 1))/2
        }
    });
    return total % mod;
};