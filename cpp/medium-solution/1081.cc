/**
1081. Smallest Subsequence of Distinct Characters
    Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

    Example :
    Input: s = "bcabc"
    Output: "abc"
 */


class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(128, 0);
        vector<bool> visited(128, false);
        string stack;

        for (char c : s) {
            freq[c]++;
        }

        for (char c : s) {
            freq[c]--;
            if (visited[c]) {
                continue;
            }

            while (!stack.empty() && stack.back() > c && freq[stack.back()] > 0) {
                visited[stack.back()] = false;
                stack.pop_back();
            }
            stack.push_back(c);
            visited[c] = true;
        }
        return stack;
    }
};