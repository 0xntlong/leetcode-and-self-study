/**
3498. Reverse Degree of a String
    Given a string s, calculate its reverse degree.
    The reverse degree is calculated as follows:
    For each character, multiply its position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed).
    Sum these products for all characters in the string.
    Return the reverse degree of s.

    Example :
    Input: s = "abc"
    Output: 148
    Explanation:
    Letter	Index in Reversed Alphabet	Index in String	Product
    'a'	26	1	26
    'b'	25	2	50
    'c'	24	3	72
    The reversed degree is 26 + 50 + 72 = 148.
 */


class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0, n = s.size();

        for (int i = 0; i < n; i++) {
            sum += (i + 1) * ('z' - s[i] + 1);
        }

        return sum;
    }
};