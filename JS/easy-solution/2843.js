/**
2843. Count Symmetric Integers
    You are given two positive integers low and high.
    An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.
    Return the number of symmetric integers in the range [low, high].

    Example :
    Input: low = 1, high = 100
    Output: 9
    Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
*/


/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var countSymmetricIntegers = function(low, high) {
    let count = 0;
    for (let num = low; num <= high; num++){
        let s = num.toString();
        if (s.length % 2 === 0){
            let mid = s.length / 2;
            let sumLeft = 0, sumRight = 0;
            for (let i = 0; i < mid; i++){
                sumLeft += parseInt(s[i], 10);
            }
            for (let i = mid; i < s.length; i++){
                sumRight += parseInt(s[i], 10);
            }
            if (sumLeft === sumRight){
                count++;
            }
        }
    }
    return count;
};