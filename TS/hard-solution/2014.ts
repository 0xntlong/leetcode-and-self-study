/**
2014. Longest Subsequence Repeated k Times
    You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.
    A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
    A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.
    For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
    Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.

    Example :
    example 1
    Input: s = "letsleetcode", k = 2
    Output: "let"
    Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
    "let" is the lexicographically largest one.
 */




function longestSubsequenceRepeatedK(s: string, k: number): string {
    const check = (sub, s, k) => {
        let count = 0, i = 0;
        for (const c of s) {
            if (i < sub.length && c === sub[i]) {
                i++;
                if (i === sub.length) {
                    i = 0;
                    count++;
                    if (count === k) 
                        return true;
                }
            }
        }
        return false;
    };

    const freq = {};
    for (const c of s) {
        freq[c] = (freq[c] || 0) + 1;
    }

    const valid: string[] = [];
    for (let c = 122; c >= 97; c--) { 
        const ch = String.fromCharCode(c);
        if ((freq[ch] || 0) >= k) {
            valid.push(ch);
        }
    }

    const maxLen = Math.floor(s.length / k);
    let res = "";
    const q = [""];
    
    while (q.length > 0) {
        const curr = q.shift();
        for (const c of valid) {
            const next = curr + c;
            if (next.length > maxLen) 
                continue;
            if (check(next, s, k)) {
                if (
                    next.length > res.length || 
                    (next.length === res.length && next > res)
                ) {
                    res = next;
                }
                q.push(next);
            }
        }
    }

    return res;
};