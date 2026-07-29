/**
3517. Smallest Palindromic Rearrangement I
    You are given a palindromic string s.
    Return the lexicographically smallest palindromic permutation of s.

    Example 1:
    Input: s = "z"
    Output: "z"
    Explanation:
    A string of only one character is already the lexicographically smallest palindrome.
 */



function smallestPalindrome(s: string): string {
    const count: Map<string, number> = new Map();

    for (const c of s) {
        count.set(c, (count.get(c) ?? 0) + 1);
    }

    const chars: string[] = [...count.keys()].sort();

    let left = "";
    let mid = "";

    for (const c of chars) {
        const freq = count.get(c)!;

        left += c.repeat(Math.floor(freq / 2));

        if (freq % 2 === 1) {
            mid = c;
        }
    }

    const right = left.split("").reverse().join("");

    return left + mid + right;
}