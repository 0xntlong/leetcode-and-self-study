/**
3756. Concatenate Non-Zero Digits and Multiply by Sum II
    You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].
    For each queries[i], extract the substring s[li..ri]. Then, perform the following:
    Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
    Let sum be the sum of digits in x. The answer is x * sum.
    Return an array of integers answer where answer[i] is the answer to the ith query.
    Since the answers may be very large, return them modulo 109 + 7.

    Example :
    Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]
    Output: [12340, 4, 9]
    Explanation:
    s[0..7] = "10203004"
    x = 1234
    sum = 1 + 2 + 3 + 4 = 10
    Therefore, answer is 1234 * 10 = 12340.
    s[1..3] = "020"
    x = 2
    sum = 2
    Therefore, the answer is 2 * 2 = 4.
    s[4..6] = "300"
    x = 3
    sum = 3
    Therefore, the answer is 3 * 3 = 9.
 */




/**
 * @param {string} s
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumAndMultiply = function(s, queries) {
    const MOD = 1000000007n;
    const n = s.length;

    const idx = Array(n + 1).fill(0);
    const val = Array(n + 1).fill(0n);
    const total = Array(n + 1).fill(0n);
    const pow10 = Array(n + 1).fill(1n);

    for (let i = 1; i <= n; i++) {
        pow10[i] = (pow10[i - 1] * 10n) % MOD;
    }

    let count = 0;

    for (let i = 0; i < n; i++) {
        const digit = BigInt(s.charCodeAt(i) - 48);

        if (digit !== 0n) {
            count++;
            val[count] = (val[count - 1] * 10n + digit) % MOD;
            total[count] = total[count - 1] + digit;
        }

        idx[i + 1] = count;
    }

    const ans = [];

    for (const [left, right] of queries) {
        const a = idx[left];
        const b = idx[right + 1];

        if (a === b) {
            ans.push(0);
            continue;
        }

        const length = b - a;

        let num = (val[b] - val[a] * pow10[length]) % MOD;
        if (num < 0n) num += MOD;

        const digitSum = total[b] - total[a];

        ans.push(Number((num * digitSum) % MOD));
    }

    return ans;
};