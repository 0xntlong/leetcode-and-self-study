/**
3445. Maximum Difference Between Even and Odd Frequency II
    You are given a string s and an integer k. Your task is to find the maximum difference between the frequency of two characters, freq[a] - freq[b], in a substring subs of s, such that:
    subs has a size of at least k.
    Character a has an odd frequency in subs.
    Character b has an even frequency in subs.
    Return the maximum difference.
    Note that subs can contain more than 2 distinct characters.

    Example :
    Input: s = "12233", k = 4
    Output: -1
    Explanation:
    For the substring "12233", the frequency of '1' is 1 and the frequency of '3' is 2. The difference is 1 - 2 = -1.
 */



function maxDifference(s: string, k: number): number {
    const n = s.length;
    const freq: number[][] = Array.from({ length: 5 }, () => Array(n + 1).fill(0));
    for (let i = 0; i < n; i++) {
        for (let d = 0; d < 5; d++) {
            freq[d][i + 1] = freq[d][i];
        }
        freq[s.charCodeAt(i) - 48][i + 1]++;
    }

    function maxDfromAtoB(a: number, b: number, k: number, n: number, freq: number[][]): number {
        const MOD = 1e8;
        let cnt = -Infinity;
        const minFreq: number[][] = [
            [MOD, MOD],
            [MOD, MOD]
        ];
        let freqA = 0, freqB = 0;
        let prevA = 0, prevB = 0;
        let l = 0;
        for (let r = k - 1; r < n; r++) {
            freqA = freq[a][r + 1];
            freqB = freq[b][r + 1];
            while (r - l + 1 >= k && freqB - prevB >= 2) {
                minFreq[prevA & 1][prevB & 1] = Math.min(minFreq[prevA & 1][prevB & 1], prevA - prevB);
                prevA = freq[a][l + 1];
                prevB = freq[b][l + 1];
                l++;
            }
            cnt = Math.max(cnt, freqA - freqB - minFreq[1 - (freqA & 1)][freqB & 1]);
        }
        return cnt;
    }

    let ans = -Infinity;
    for (let a = 0; a < 5; a++) {
        if (freq[a][n] === 0) continue;
        for (let b = 0; b < 5; b++) {
            if (a === b || freq[b][n] === 0) continue;
            ans = Math.max(ans, maxDfromAtoB(a, b, k, n, freq));
        }
    }
    return ans;
}