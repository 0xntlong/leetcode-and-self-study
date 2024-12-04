/*
2825. Make String a Subsequence Using Cyclic Increments
    You are given two 0-indexed strings str1 and str2.
    In an operation, you select a set of indices in str1, and for each index i in the set, increment str1[i] to the next character cyclically. That is 'a' becomes 'b', 'b' becomes 'c', and so on, and 'z' becomes 'a'.
    Return true if it is possible to make str2 a subsequence of str1 by performing the operation at most once, and false otherwise.
    Note: A subsequence of a string is a new string that is formed from the original string by deleting some (possibly none) of the characters without disturbing the relative positions of the remaining characters.

    Example :
    Input: str1 = "abc", str2 = "ad"
    Output: true
    Explanation: Select index 2 in str1.
    Increment str1[2] to become 'd'. 
    Hence, str1 becomes "abd" and str2 is now a subsequence. Therefore, true is returned.
*/

#include <string>
using namespace std;
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int idx = 0;
        int s2 = str2.length();
        for (char curr : str1){
            if (idx < s2 && (str2[idx] - curr + 26) % 26 <= 1){
                idx++;
            } 
        }
        return idx == s2;
    }
};