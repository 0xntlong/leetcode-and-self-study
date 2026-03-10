/**
3130. Find All Possible Stable Binary Arrays II
    You are given 3 positive integers zero, one, and limit.
    A binary array arr is called stable if:
    The number of occurrences of 0 in arr is exactly zero.
    The number of occurrences of 1 in arr is exactly one.
    Each subarray of arr with a size greater than limit must contain both 0 and 1.
    Return the total number of stable binary arrays.
    Since the answer may be very large, return it modulo 109 + 7.

    Example:
    Input: zero = 1, one = 1, limit = 2
    Output: 2
    Explanation:
    The two possible stable binary arrays are [1,0] and [0,1].


 */



function numberOfStableArrays(zero: number, one: number, limit: number): number {
    const mod = 1000000007n;

    function comp(i: number): bigint[] {
        let ways: bigint[] = Array(i + 1).fill(0n);
        let prev: bigint[] = Array(i + 1).fill(0n);
        prev[0] = 1n;

        for (let k = 1; k <= i; k++) {
            let curr: bigint[] = Array(i + 1).fill(0n);
            let pref = 0n;

            for (let j = 1; j <= i; j++) {
                pref = (pref + prev[j - 1]) % mod;
                if (j - limit - 1 >= 0) {
                    pref = (pref - prev[j - limit - 1] + mod) % mod;
                }
                curr[j] = pref;
            }

            ways[k] = curr[i];
            prev = curr;
        }

        return ways;
    }

    const Zero = comp(zero);
    const One = comp(one);
    let ans = 0n;

    for (let a = 1; a <= zero; a++) {
        if (a <= one) {
            ans = (ans + (Zero[a] * One[a]) % mod) % mod;
        }
        if (a - 1 >= 1 && a - 1 <= one) {
            ans = (ans + (Zero[a] * One[a - 1]) % mod) % mod;
        }
    }

    for (let a = 1; a <= zero; a++) {
        if (a <= one) {
            ans = (ans + (Zero[a] * One[a]) % mod) % mod;
        }
        if (a + 1 <= one) {
            ans = (ans + (Zero[a] * One[a + 1]) % mod) % mod;
        }
    }

    return Number(ans % mod);
};