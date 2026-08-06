/**
3345. Smallest Divisible Digit Product I
    You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.
    Example :
    Input: n = 10, t = 2
    Output: 10
    Explanation:
    The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.
 */



/**
 * @param {number} n
 * @param {number} t
 * @return {number}
 */
var smallestNumber = function(n, t) {
    for (let i = n; i < n + 1000; i++) {
        let x = i;
        let product = 1;

        while (x > 0) {
            product *= x % 10;
            x = Math.floor(x / 10);
        }

        if (product % t === 0) {
            return i;
        }
    }

    return -1;
};