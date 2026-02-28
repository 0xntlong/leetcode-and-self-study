/**
1680. Concatenation of Consecutive Binary Numbers
    Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

    Example :
    Input: n = 1
    Output: 1
    Explanation: "1" in binary corresponds to the decimal value 1. 
 */



/**
 * @param {number} n
 * @return {number}
 */
var concatenatedBinary = function(n) {
    const MOD = 1000000007n;
    let res = 0n;

    for (let i = 1n; i <= BigInt(n); i++) {
        const bits = i.toString(2).length;
        res = ((res << BigInt(bits)) + i) % MOD;
    }

    return Number(res);
};