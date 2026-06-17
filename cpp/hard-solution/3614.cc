/**
3614. Process String with Special Operations II
    You are given a string s consisting of lowercase English letters and the special characters: '*', '#', and '%'.
    You are also given an integer k.
    Build a new string result by processing s according to the following rules from left to right:
    If the letter is a lowercase English letter append it to result.
    A '*' removes the last character from result, if it exists.
    A '#' duplicates the current result and appends it to itself.
    A '%' reverses the current result.
    Return the kth character of the final string result. If k is out of the bounds of result, return '.'.

    Example :
    Input: s = "a#b%*", k = 1
    Output: "a"
    Explanation:
    i	s[i]	Operation	Current result
    0	'a'	Append 'a'	"a"
    1	'#'	Duplicate result	"aa"
    2	'b'	Append 'b'	"aab"
    3	'%'	Reverse result	"baa"
    4	'*'	Remove the last character	"ba"
    The final result is "ba". The character at index k = 1 is 'a'.
 */


class Solution {
public:
    char processStr(string s, long long k) {
        long long L = 0;
        for (char c : s) {
            if (c == '*') {
                if (L > 0) L--;
            } else if (c == '#') {
                L *= 2;
            } else if (c == '%') {
                continue;
            } else {
                L++;
            }
        }
        if (k >= L) return '.';
        long long p = k;
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == '*') {
                L++;
            } else if (c == '#') {
                if (p >= L / 2) {
                    p -= L / 2;
                }
                L /= 2;
            } else if (c == '%') {
                p = L - 1 - p;
            } else {
                if (L == p + 1) {
                    return c;
                }
                L--;
            }
        }
        return '.';
    }
};