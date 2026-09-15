/**
2472. Maximum Number of Non-overlapping Palindrome Substrings
    You are given a string s and a positive integer k.
    Select a set of non-overlapping substrings from the string s that satisfy the following conditions:
    The length of each substring is at least k.
    Each substring is a palindrome.
    Return the maximum number of substrings in an optimal selection.
    A substring is a contiguous sequence of characters within a string.
    Example :
    Input: s = "abaccdbbd", k = 3
    Output: 2
    Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
    It can be shown that we cannot find a selection with more than two valid substrings.
 */


#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;
        int lastEnd = 0;

        for (int right = k - 1; right < n; right++) {
            int left = right - k + 1;

            bool add =
                (left >= lastEnd && isPalindrome(s, left, right)) ||
                (left > lastEnd && isPalindrome(s, left - 1, right));

            if (add) {
                count++;
                lastEnd = right + 1;
            }
        }

        return count;
    }
};