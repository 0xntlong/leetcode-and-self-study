/**
1007. Minimum Domino Rotations For Equal Row
    In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
    We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
    Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
    If it cannot be done, return -1.

    Example :
    Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
    Output: 2
    Explanation: 
    The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
    If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
 */

/**
 * @param {number[]} tops
 * @param {number[]} bottoms
 * @return {number}
 */
var minDominoRotations = function(tops, bottoms) {
    const n = tops.length, m = bottoms.length;
    if (n !== m){
        return -1;
    }

    const TOPS = Array(7).fill(0);
    const BOTTOMS = Array(7).fill(0);
    const SAME = Array(7).fill(0);

    for (let i = 0; i < n; i++){
        TOPS[tops[i]]++;
        BOTTOMS[bottoms[i]]++;
        if (tops[i] === bottoms[i])
            SAME[tops[i]]++;
    }
    let res = Infinity;
    for (let j = 1; j <= 6; j++){
        if (TOPS[j] + BOTTOMS[j] - SAME[j] === n){
            res = Math.min(res, Math.min(n - TOPS[j], n - BOTTOMS[j]));
        }
    }
    return res === Infinity ? -1 : res;
};