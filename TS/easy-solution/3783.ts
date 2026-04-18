/**
3783. Mirror Distance of an Integer
    You are given an integer n.
    Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.
    Return an integer denoting the mirror distance of n​​​​​​​.
    abs(x) denotes the absolute value of x.

    Example :
    Input: n = 25
    Output: 27
    Explanation:
    reverse(25) = 52.
    Thus, the answer is abs(25 - 52) = 27.
 */


function mirrorDistance(n: number): number {
    let reversion = 0;
    let x = n;

    while (x > 0) {
        let r = x % 10;
        x = Math.floor(x / 10);
        reversion = reversion * 10 + r;
    }

    return Math.abs(reversion - n);
};