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

 /**
 * @param {number} n
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
const MOD = BigInt(1e9 + 7);
const MAX = 100000;
const fact = Array(MAX).fill(0n);   
const inv = Array(MAX).fill(0n);    

const modPow = (x, y) => {           
    x = BigInt(x);
    y = BigInt(y);
    let result = 1n;
    while (y > 0n) {
        if (y & 1n) result = (result * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1n;
    }
    return result;
};

const computeFact = () => {         
    if (fact[0] !== 0n) return;
    fact[0] = 1n;
    for (let i = 1; i < MAX; i++) fact[i] = (fact[i - 1] * BigInt(i)) % MOD;
    inv[MAX - 1] = modPow(fact[MAX - 1], MOD - 2n);
    for (let i = MAX - 2; i >= 0; i--) inv[i] = (inv[i + 1] * BigInt(i + 1)) % MOD;
};

const comb = (n, r) => {             
    if (r < 0 || r > n) return 0n;
    return (((fact[n] * inv[r]) % MOD) * inv[n - r]) % MOD;
};

const countGoodArrays = (n, m, k) => {
    computeFact();  
    let ways = comb(n - 1, k);
    ways = (ways * BigInt(m)) % MOD;
    ways = (ways * modPow(m - 1, n - k - 1)) % MOD;
    return Number(ways);
};