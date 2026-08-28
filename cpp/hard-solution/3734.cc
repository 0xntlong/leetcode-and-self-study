/**
3734. Lexicographically Smallest Palindromic Permutation Greater Than Target
    You are given two strings s and target, each of length n, consisting of lowercase English letters.
    Return the lexicographically smallest string that is both a palindromic permutation of s and strictly greater than target. If no such permutation exists, return an empty string.
    Example :
    Input: s = "baba", target = "abba"
    Output: "baab"
    Explanation:
    The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
    The lexicographically smallest permutation that is strictly greater than target is "baab".
 */


#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string middle = "";

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                if (!middle.empty()) {
                    return "";
                }

                middle += char('a' + i);
            }

            freq[i] /= 2;
        }

        int halfLen = n / 2;
        string half = "";

        int matched = 0;

        while (matched < halfLen) {
            int c = target[matched] - 'a';

            if (freq[c] == 0) {
                break;
            }

            freq[c]--;
            half += char('a' + c);
            matched++;
        }

        int i = matched;

        while (i >= 0) {
            if (i < halfLen) {
                int start = target[i] - 'a' + 1;

                for (int c = start; c < 26; c++) {
                    if (freq[c] == 0) {
                        continue;
                    }

                    freq[c]--;

                    string suffix = "";

                    for (int j = 0; j < 26; j++) {
                        suffix += string(
                            freq[j],
                            char('a' + j)
                        );
                    }

                    string left =
                        half.substr(0, i)
                        + char('a' + c)
                        + suffix;

                    string rev = left;
                    reverse(rev.begin(), rev.end());

                    string candidate =
                        left + middle + rev;

                    if (candidate > target) {
                        return candidate;
                    }

                    freq[c]++;
                }
            }

            if (i == halfLen) {
                string left = half;

                string rev = left;
                reverse(rev.begin(), rev.end());

                string candidate =
                    left + middle + rev;

                if (candidate > target) {
                    return candidate;
                }
            }

            i--;

            if (i >= 0) {
                int c = half[i] - 'a';
                freq[c]++;
                half.pop_back();
            }
        }

        return "";
    }
};