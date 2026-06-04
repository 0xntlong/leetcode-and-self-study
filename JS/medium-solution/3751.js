/**
3751. Total Waviness of Numbers in Range I
    You are given two integers num1 and num2 representing an inclusive range [num1, num2].
    The waviness of a number is defined as the total count of its peaks and valleys:
    A digit is a peak if it is strictly greater than both of its immediate neighbors.
    A digit is a valley if it is strictly less than both of its immediate neighbors.
    The first and last digits of a number cannot be peaks or valleys.
    Any number with fewer than 3 digits has a waviness of 0.
    Return the total sum of waviness for all numbers in the range [num1, num2].
    

    Example :
    Input: num1 = 120, num2 = 130
    Output: 3
    Explanation:
    In the range [120, 130]:
    120: middle digit 2 is a peak, waviness = 1.
    121: middle digit 2 is a peak, waviness = 1.
    130: middle digit 3 is a peak, waviness = 1.
    All other numbers in the range have a waviness of 0.
    Thus, total waviness is 1 + 1 + 1 = 3.
 */



/**
 * @param {number} num1
 * @param {number} num2
 * @return {number}
 */
var totalWaviness = function(num1, num2) {
    let total = 0;
    for (let num = num1; num <= num2; num++) {
        const n = num.toString();
        if (n.length < 3) 
            continue;
        
        for (let i = 1; i < n.length - 1; i++) {
            if ((n[i] > n[i - 1] && n[i] > n[i + 1]) || 
                (n[i] < n[i - 1] && n[i] < n[i + 1])) {
                total++;
            }
        }
    }
    return total;
};