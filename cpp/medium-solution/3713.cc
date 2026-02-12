/**
3713. Longest Balanced Substring I
    You are given a string s consisting of lowercase English letters.
    A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
    Return the length of the longest balanced substring of s.

    Example:
    Input: s = "abbac"
    Output: 4
    Explanation:

    The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
            a[i] = s[i] - 'a';

        int res = 0;
        for (int l = 0; l < n; l++) {
            if (n - l <= res) 
                break;

            int freq[26] = {0};
            int unique = 0, maxFreq = 0;

            for (int r = l; r < n; r++) {
                int idx = a[r];
                if (freq[idx] == 0) 
                    unique++;
                freq[idx]++;
                if (freq[idx] > maxFreq) 
                    maxFreq = freq[idx];
                int curr = r - l + 1;
                if (unique * maxFreq == curr) {
                    if (curr > res) 
                        res = curr;
                }
            }
        }
        return res;
    }
};