/*
3335. Total Characters in String After Transformations I
    You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:
    If the character is 'z', replace it with the string "ab".
    Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
    Return the length of the resulting string after exactly t transformations.
    Since the answer may be very large, return it modulo 109 + 7.

    Example :
    Input: s = "abcyy", t = 2
    Output: 7
    Explanation:
    First Transformation (t = 1):
    'a' becomes 'b'
    'b' becomes 'c'
    'c' becomes 'd'
    'y' becomes 'z'
    'y' becomes 'z'
    String after the first transformation: "bcdzz"
    Second Transformation (t = 2):
    'b' becomes 'c'
    'c' becomes 'd'
    'd' becomes 'e'
    'z' becomes "ab"
    'z' becomes "ab"
    String after the second transformation: "cdeabab"
    Final Length of the string: The string is "cdeabab", which has 7 characters.
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        int freq[26] = {0};
        for (char c : s){
            freq[c - 'a']++;
        }
        for (t; t > 0; t--){
            long long alphabet = freq[25];
            long long f0 = freq[0];
            for (int i = 25; i >= 2; i--){
                freq[i] = freq[i - 1];
            }
            freq[0] = alphabet;
            f0 += alphabet;
            if (f0 >= mod){
                f0 -= mod;
            }
            freq[1] = f0;
        }
        return reduce(freq, freq + 26, 0LL) % mod;
    }
};