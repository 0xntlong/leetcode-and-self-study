/**
1550. Three Consecutive Odds
    Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
    Example :
    Input: arr = [2,6,4,1]
    Output: false
    Explanation: There are no three consecutive odds.
 */


/**
 * @param {number[]} arr
 * @return {boolean}
 */
var threeConsecutiveOdds = function(arr) {
    if (arr.length < 3){
        return false;
    }
    for (let i = 0; i < arr.length - 2; i++){
        if (arr[i] % 2 !== 0 && arr[i + 1] % 2 !== 0 && arr[i + 2] % 2 !== 0){
            return true;
        }
    }
    return false;
};