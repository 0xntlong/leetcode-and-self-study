/**
1461. Check If a String Contains All Binary Codes of Size K
    Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
    Example :
    Input: s = "00110110", k = 2
    Output: true
    Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
 */

function hasAllCodes(s: string, k: number): boolean {
    const req = 1 << k;
    const n = s.length;
    if (req > n - k + 1) 
        return false;

    const seen: boolean[] = new Array(req).fill(false);
    const mask = req - 1;
    let code = 0;
    let found = 0;

    for (let i = 0; i < n; i++) {
        code = ((code << 1) & mask) | (s[i] === '1' ? 1 : 0);
        if (i >= k - 1 && !seen[code]) {
            seen[code] = true;
            if (++found === req) 
                return true;
        }
    }
    return false;
};