/**
2573. Find the String with LCP
    We define the lcp matrix of any 0-indexed string word of n lowercase English letters as an n x n grid such that:

    lcp[i][j] is equal to the length of the longest common prefix between the substrings word[i,n-1] and word[j,n-1].
    Given an n x n matrix lcp, return the alphabetically smallest string word that corresponds to lcp. If there is no such string, return an empty string.

    A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "aabd" is lexicographically smaller than "aaca" because the first position they differ is at the third letter, and 'b' comes before 'c'.

    

    Example 1:

    Input: lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
    Output: "abab"
    Explanation: lcp corresponds to any 4 letter string with two alternating letters. The lexicographically smallest of them is "abab".
 */


#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        vector<int> s(n, 0);
        int val = 1;

        for (int i = 0; i < n; i++) {
            if (s[i] > 0) {
                continue;
            }
            if (val > 26) {
                return "";
            }
            for (int j = i; j < n; j++) {
                if (lcp[i][j] > 0) {
                    s[j] = val;
                }
            }
            val++;
        }

        string res = "";
        for (int i = 0; i < n; i++) {
            res += char('a' + s[i] - 1);
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int new_val = 0;
                if (res[i] == res[j]) {
                    new_val = 1;
                    if (i + 1 < n && j + 1 < n) {
                        new_val += lcp[i + 1][j + 1];
                    }
                }
                if (lcp[i][j] != new_val) {
                    return "";
                }
            }
        }
        return res;
    }
};