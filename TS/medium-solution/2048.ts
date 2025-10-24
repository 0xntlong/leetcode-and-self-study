/**
2048. Next Greater Numerically Balanced Number
    An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
    Given an integer n, return the smallest numerically balanced number strictly greater than n.

    Example :
    Input: n = 1
    Output: 22
    Explanation: 
    22 is numerically balanced since:
    - The digit 2 occurs 2 times. 
    It is also the smallest numerically balanced number strictly greater than 1.
 */



function nextBeautifulNumber(n: number): number {
    function balance(num: number): boolean {
        const s = num.toString();
        const freq: number[] = new Array(10).fill(0);
        for (const c of s)
            freq[+c]++;
        for (const c of s) {
            const digit = +c;
            if (freq[digit] !== digit)
                return false;
        }
        return true;
    }

    n++;
    while (!balance(n)) {
        n++;
    }
    return n;
};