/**
2338. Count the Number of Ideal Arrays
    You are given two integers n and maxValue, which are used to describe an ideal array.
    A 0-indexed integer array arr of length n is considered ideal if the following conditions hold:
    Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
    Every arr[i] is divisible by arr[i - 1], for 0 < i < n.
    Return the number of distinct ideal arrays of length n. Since the answer may be very large, return it modulo 109 + 7.
    Example :
    Input: n = 2, maxValue = 5
    Output: 10
    Explanation: The following are the possible ideal arrays:
    - Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
    - Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
    - Arrays starting with the value 3 (1 array): [3,3]
    - Arrays starting with the value 4 (1 array): [4,4]
    - Arrays starting with the value 5 (1 array): [5,5]
    There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
 */

    const MOD = 1e9 + 7;
    const MAX = 10001;
    const cnt: number[][] = Array.from({length: MAX}, () => Array(14).fill(0));
    const dp: number[][] = Array.from({length: MAX}, () => Array(14).fill(0));

    for (let i = 0; i < MAX; i++) {
        dp[i][0] = 1;
        for (let j = 1; j <= Math.min(i, 13); j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    for (let cur = 1; cur < MAX; cur++) {
        cnt[cur][0]++;
        for (let i = cur * 2; i < MAX; i += cur) {
            for (let bars = 0; bars < 13; bars++) {
                if (cnt[cur][bars]) {
                    cnt[i][bars + 1] += cnt[cur][bars];
                }
            }
        }
    }

    function idealArrays(n: number, maxValue: number): number {
        let res = 0;
        for (let i = 0; i <= maxValue; i++) {
            for (let bars = 0; bars < Math.min(14, n); bars++) {
                res = (res + cnt[i][bars] * dp[n - 1][bars]) % MOD;
            }
        }
        return res;
    }