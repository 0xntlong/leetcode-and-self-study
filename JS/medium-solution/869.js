/**
869. Reordered Power of 2
    You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
    Return true if and only if we can do this so that the resulting number is a power of two.

    Example 1:
    Input: n = 1
    Output: true
 */




/**
 * @param {number} n
 * @return {boolean}
 */
var reorderedPowerOf2 = function(n) {
    const s = [...String(n)].sort().join('');
    for (let i = 0; i < 31; i++){
        const power = 1 << i;
        if (s === [...String(power)].sort().join('')){
            return true;
        }
    }
    return false;
};