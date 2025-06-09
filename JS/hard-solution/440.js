/**
440. K-th Smallest in Lexicographical Order
    Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

    Example 1:
    Input: n = 13, k = 2
    Output: 10
    Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
 */



/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findKthNumber = function(n, k) {
    const count = (n, a, b) => {
        let total = 0;
        while (a <= n){
            total += Math.min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return total;
    };
    let res = 1;
    k--;
    while (k > 0){
        let steps = count(n, res, res + 1);
        if (steps <= k){
            k -= steps;
            res += 1;
        } else {
            res *= 10;
            k -= 1
        }
    }
    return res;
};