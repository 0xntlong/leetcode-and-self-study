/**
3666. Minimum Operations to Equalize Binary String
    You are given a binary string s, and an integer k.
    In one operation, you must choose exactly k different indices and flip each '0' to '1' and each '1' to '0'.
    Return the minimum number of operations required to make all characters in the string equal to '1'. If it is not possible, return -1.

    Example :
    Input: s = "110", k = 1
    Output: 1
    Explanation:
    There is one '0' in s.
    Since k = 1, we can flip it directly in one operation.
 */



function minOperations(s: string, k: number): number {
    const n = s.length;
    let zero = 0;
    for (const ch of s) if (ch === '0') zero++;

    if (n === k) {
        if (zero === 0) 
            return 0;
        if (zero === n) 
            return 1;
        return -1;
    }

    const ceilDiv = (x: number, y: number): number => Math.floor((x + y - 1) / y);
    const INF = 1e18;
    let res = INF;

    if (zero % 2 === 0) {
        let m = Math.max(ceilDiv(zero, k), ceilDiv(zero, n - k));
        if (m % 2 === 1) 
            m++;
        res = Math.min(res, m);
    }

    if (zero % 2 === (k % 2)) {
        let m = Math.max(ceilDiv(zero, k), ceilDiv(n - zero, n - k));
        if (m % 2 === 0) 
            m++;
        res = Math.min(res, m);
    }

    return res < INF ? res : -1;
};