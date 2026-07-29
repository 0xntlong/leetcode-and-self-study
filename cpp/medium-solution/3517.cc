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

#include <string>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> count;

        for (char c : s) {
            count[c]++;
        }

        string left;
        char mid = '\0';

        for (auto& [c, freq] : count) {
            left += string(freq / 2, c);

            if (freq % 2 == 1) {
                mid = c;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid != '\0') {
            return left + string(1, mid) + right;
        }

        return left + right;
    }
};