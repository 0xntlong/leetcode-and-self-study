/**
1513. Number of Substrings With Only 1s
    Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.
    Example :
    Input: s = "0110111"
    Output: 9
    Explanation: There are 9 substring in total with only 1's characters.
    "1" -> 5 times.
    "11" -> 3 times.
    "111" -> 1 time.
 */



function numSub(s: string): number {
    const mod = 1_000_000_007;
    let cnt = 0, cur = 0;

    for (const c of s) {
        if (c === '1') {
            cur++;
        } else {
            cnt += cur * (cur + 1);
            cur = 0;
        }
    }
    cnt += cur * (cur + 1);

    return Math.floor(cnt / 2) % mod;
};