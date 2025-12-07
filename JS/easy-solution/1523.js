/*
1523. Count Odd Numbers in an Interval Range
    Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
    
    Example :
    Input: low = 3, high = 7
    Output: 3
    Explanation: The odd numbers between 3 and 7 are [3,5,7].
*/



/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var countOdds = function(low, high) {
    if (low & 1){
        return Math.floor((high - low + 2) / 2);
    }
    return Math.floor((high - low + 1) / 2);
};