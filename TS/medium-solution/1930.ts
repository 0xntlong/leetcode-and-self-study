/*
1930. Unique Length-3 Palindromic Subsequences
    Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
    Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
    A palindrome is a string that reads the same forwards and backwards.
    A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
    For example, "ace" is a subsequence of "abcde".

    Example :
    Input: s = "aabca"
    Output: 3
    Explanation: The 3 palindromic subsequences of length 3 are:
    - "aba" (subsequence of "aabca")
    - "aaa" (subsequence of "aabca")
    - "aca" (subsequence of "aabca")
*/



function countPalindromicSubsequence(s: string): number {
    if (s.length <= 2){
        return 0;
    }
    const chars = new Set(s);
    let res = 0; 
    for (const c of chars){
        const left = s.indexOf(c);
        const right = s.lastIndexOf(c);
        if (left != right){
            const mid = new Set<string>();
            for (let i = left + 1; i < right; i++){
                mid.add(s[i]);
            }
            res += mid.size;
        }
    }
    return res;
};