/**
3622. Check Divisibility by Digit Sum and Product
    You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:
    The digit sum of n (the sum of its digits).
    The digit product of n (the product of its digits).
    Return true if n is divisible by this sum; otherwise, return false.
    Example :
    Input: n = 99
    Output: true
    Explanation:
    Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 * 9 = 81) of its digits (total 99), the output is true.
 */



function checkDivisibility(n: number): boolean {
    let s: number = 0;
    let p: number = 1;

    const str: string = Math.abs(n).toString();

    for (const ch of str) {
        const d: number = Number(ch);
        s += d;
        p *= d;
    }

    if (n % (s + p) === 0) {
        return true;
    } else {
        return false;
    }
};