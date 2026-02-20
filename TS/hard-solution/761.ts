/**
761. Special Binary String
    Special binary strings are binary strings with the following two properties:
    The number of 0's is equal to the number of 1's.
    Every prefix of the binary string has at least as many 1's as 0's.
    You are given a special binary string s.
    A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.
    Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.

    Example:
    Input: s = "11011000"
    Output: "11100100"
    Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
    This is the lexicographically largest string possible after some number of swaps.
 */


function makeLargestSpecial(s: string): string {
    let res: string[] = [];
    let cnt = 0, idx = 0;

    for (let i = 0; i < s.length; i++) {
        if (s[i] === '1') 
            cnt++;
        else 
            cnt--;

        if (cnt === 0) {
            const inner = makeLargestSpecial(s.slice(idx + 1, i));
            res.push("1" + inner + "0");
            idx = i + 1;
        }
    }

    res.sort().reverse();
    return res.join("");
};