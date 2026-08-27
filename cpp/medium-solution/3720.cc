/**
3720. Lexicographically Smallest Permutation Greater Than Target
    You are given two strings s and target, both having length n, consisting of lowercase English letters.
    Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.
    A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.

    Example :
    Input: s = "abc", target = "bba"
    Output: "bca"
    Explanation:
    The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
    The lexicographically smallest permutation that is strictly greater than target is "bca".
 */


#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        int p = 0;

        while (p < n) {
            int c = target[p] - 'a';

            if (cnt[c] == 0) {
                break;
            }

            cnt[c]--;
            p++;
        }

        int i = p;

        while (i >= 0) {
            if (i < n) {
                int t = target[i] - 'a';
                int pick = -1;

                for (int c = t + 1; c < 26; c++) {
                    if (cnt[c] > 0) {
                        pick = c;
                        break;
                    }
                }

                if (pick >= 0) {
                    cnt[pick]--;

                    string tail = "";

                    for (int c = 0; c < 26; c++) {
                        tail += string(cnt[c], char('a' + c));
                    }

                    cnt[pick]++;

                    return target.substr(0, i)
                        + char('a' + pick)
                        + tail;
                }
            }

            i--;

            if (i >= 0) {
                cnt[target[i] - 'a']++;
            }
        }

        return "";
    }
};