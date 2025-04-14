/**
1534. Count Good Triplets
    Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.
    A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:
    0 <= i < j < k < arr.length
    |arr[i] - arr[j]| <= a
    |arr[j] - arr[k]| <= b
    |arr[i] - arr[k]| <= c
    Where |x| denotes the absolute value of x.
    Return the number of good triplets.

    Example :
    Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
    Output: 4
    Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
 */


/**
 * @param {number[]} arr
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var countGoodTriplets = function(arr, a, b, c) {
    const n = arr.length;
    let cnt = 0;
    for (let i = 0; i < n - 2; i++){
        const x = arr[i];
        for (let j = i + 1; j < n - 1; j++){
            const y = arr[j];
            if (Math.abs(x - y) > a)
                continue;
            for (let k = j + 1; k < n; k++){
                const z = arr[k];
                if (Math.abs(y - z) > b)
                    continue;
                if (Math.abs(x - z) <= c){
                    cnt++;
                }
            }
        }
    }
    return cnt;
};