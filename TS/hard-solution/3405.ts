/**
3405. Count the Number of Arrays with K Matching Adjacent Elements
    You are given three integers n, m, k. A good array arr of size n is defined as follows:
    Each element in arr is in the inclusive range [1, m].
    Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
    Return the number of good arrays that can be formed.
    Since the answer may be very large, return it modulo 109 + 7.

    Example :
    Input: n = 3, m = 2, k = 1
    Output: 4
    Explanation:
    There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2, 2, 1].
    Hence, the answer is 4.
 */


const MOD3405: bigint = 1000000007n;
const MX: number = 100000;

const fact: bigint[] = new Array(MX).fill(0n);
const invFact: bigint[] = new Array(MX).fill(0n);
let built: boolean = false;

function Pow(x: number | bigint, n: number | bigint): bigint {
    x = BigInt(x);
    n = BigInt(n);
    let res = 1n;
    while (n > 0n) {
        if ((n & 1n) === 1n) {
            res = (res * x) % MOD3405;
        }
        x = (x * x) % MOD3405;
        n >>= 1n;
    }
    return res;
}

function init(): void {
    if (fact[0] !== 0n) {
        return;
    }
    fact[0] = 1n;
    for (let i = 1; i < MX; i++) {
        fact[i] = (fact[i - 1] * BigInt(i)) % MOD3405;
    }

    invFact[MX - 1] = Pow(fact[MX - 1], MOD3405 - 2n);
    for (let i = MX - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * BigInt(i + 1)) % MOD3405;
    }
}

function comb(n: number, m: number): bigint {
    if (m < 0 || m > n) {
        return 0n;
    }
    return (((fact[n] * invFact[m]) % MOD3405) * invFact[n - m]) % MOD3405;
}

function countGoodArrays(n: number, m: number, k: number): number {
    init();
    let res = comb(n - 1, k);
    res = (res * BigInt(m)) % MOD3405;
    res = (res * Pow(BigInt(m - 1), BigInt(n - k - 1))) % MOD3405;
    return Number(res);
}