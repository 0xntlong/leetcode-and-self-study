/**
3234. Count the Number of Substrings With Dominant Ones
    You are given a binary string s.
    Return the number of substrings with dominant ones.
    A string has dominant ones if the number of ones in the string is greater than or equal to the square of the number of zeros in the string.

    Example 1:
    Input: s = "00011"
    Output: 5
    Explanation:
    The substrings with dominant ones are shown in the table below.
    i	j	s[i..j]	Number of Zeros	Number of Ones
    3	3	1	0	1
    4	4	1	0	1
    2	3	01	1	1
    3	4	11	0	2
    2	4	011	1	2
 */



function numberOfSubstrings(s: string): number {
    const n = s.length;
    const dp: number[] = Array(n + 1).fill(-1);

    for (let i = 0; i < n; i++) {
        if (i === 0 || s[i - 1] === '0')
            dp[i + 1] = i;
        else
            dp[i + 1] = dp[i];
    }

    let res = 0;

    for (let i = 1; i <= n; i++) {
        let cnt0 = (s[i - 1] === '0') ? 1 : 0;
        let j = i;

        while (j > 0 && cnt0 * cnt0 <= n) {
            const cnt1 = (i - dp[j]) - cnt0;
            if (cnt0 * cnt0 <= cnt1) {
                res += Math.min(j - dp[j], cnt1 - cnt0 * cnt0 + 1);
            }
            j = dp[j];
            cnt0++;
        }
    }

    return res;
};