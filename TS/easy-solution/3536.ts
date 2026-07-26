/**
3536. Maximum Product of Two Digits
    You are given a positive integer n.
    Return the maximum product of any two digits in n.
    Note: You may use the same digit twice if it appears more than once in n.


    Example :
    Input: n = 31
    Output: 3
    Explanation:

    The digits of n are [3, 1].
    The possible products of any two digits are: 3 * 1 = 3.
    The maximum product is 3.
 */



function maxProduct1(n: number): number {
    const s = String(n).split('').sort();

    const d1 = Number(s[s.length - 2]);
    const d2 = Number(s[s.length - 1]);

    return d1 * d2;
};