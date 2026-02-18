/**
693. Binary Number with Alternating Bits
    Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
    Example :
    Input: n = 5
    Output: true
    Explanation: The binary representation of 5 is: 101
 */


/**
 * @param {number} n
 * @return {boolean}
 */
var hasAlternatingBits = function(n) {
    let prev = n & 1;
    n >>= 1;

    while (n > 0) {
        let cur = n & 1;
        if (cur === prev) 
            return false;
        prev = cur;
        n >>= 1;
    }
    return true;
};