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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> left(26, INT_MAX);
        vector<int> right(26, -1);
        int res = 0;
        for (int i = 0; i < s.size(); i++){
            left[s[i] - 'a'] = min(left[s[i] - 'a'], i);
            right[s[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; i++){
            if (left[i] < right[i]){
                unordered_set<char> uniqueChar;
                for (int j = left[i] + 1; j < right[i]; j++){
                    uniqueChar.insert(s[j]);
                }
                res += uniqueChar.size();
            }
        }
        return res;
    }
};