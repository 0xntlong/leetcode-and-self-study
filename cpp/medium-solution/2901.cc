/*
2901. Longest Unequal Adjacent Groups Subsequence II
    You are given a string array words, and an array groups, both arrays having length n.
    The hamming distance between two strings of equal length is the number of positions at which the corresponding characters are different.
    You need to select the longest subsequence from an array of indices [0, 1, ..., n - 1], such that for the subsequence denoted as [i0, i1, ..., ik-1] having length k, the following holds:
    For adjacent indices in the subsequence, their corresponding groups are unequal, i.e., groups[ij] != groups[ij+1], for each j where 0 < j + 1 < k.
    words[ij] and words[ij+1] are equal in length, and the hamming distance between them is 1, where 0 < j + 1 < k, for all indices in the subsequence.
    Return a string array containing the words corresponding to the indices (in order) in the selected subsequence. If there are multiple answers, return any of them.
    Note: strings in words may be unequal in length.

    Example 1:
    Input: words = ["bab","dab","cab"], groups = [1,2,2]
    Output: ["bab","cab"]
    Explanation: A subsequence that can be selected is [0,2].
    groups[0] != groups[2]
    words[0].length == words[2].length, and the hamming distance between them is 1.
    So, a valid answer is [words[0],words[2]] = ["bab","cab"].
    Another subsequence that can be selected is [0,1].
    groups[0] != groups[1]
    words[0].length == words[1].length, and the hamming distance between them is 1.
    So, another valid answer is [words[0],words[1]] = ["bab","dab"].
    It can be shown that the length of the longest subsequence of indices that satisfies the conditions is 2.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool hamming(const string& s, const string& t){
        if (s.size() != t.size()) return false;
        int diff = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] != t[i]){
                diff++;
                if (diff > 1){
                    return false;
                }
            }
        }
        return diff == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1), nxt(n, -1);
        int max_len = 0, start = -1;
        for (int i = n - 1; i >= 0; i--){
            for (int j = i + 1; j < n; j++){
                if (groups[i] != groups[j] && hamming(words[i], words[j])){
                    if (dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        nxt[i] = j;
                    }
                }
            }
            if (dp[i] > max_len){
                max_len = dp[i];
                start = i;
            }
        }
        vector<string> res;
        while (start != -1){
            res.push_back(words[start]);
            start = nxt[start];
        }
        return res;
    }
};