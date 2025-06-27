/*
2014. Longest Subsequence Repeated k Times
    You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.
    A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
    A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.
    For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
    Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.

    Example :
    example 1
    Input: s = "letsleetcode", k = 2
    Output: "let"
    Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
    "let" is the lexicographically largest one.

 */

#include <string>
#include <unordered_map>
#include <vector>
#include <queue> 
using namespace std;

class Solution {
public:
    bool check(const string& sub, const string& s, int k){
        int count = 0, i = 0;
        for (char c : s){
            if (i < sub.size() && c == sub[i]){
                i++;
                if (i == sub.size()){
                    i = 0;
                    count++;
                    if (count == k)
                        return true;
                }
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) 
            freq[c]++;
        vector<char> valid_chars;
        for (char c = 'z'; c >= 'a'; c--)
            if (freq[c] >= k)
                valid_chars.push_back(c);

        int max_len = s.size() / k;
        string res = "";
        queue<string> q;
        q.push("");
        while (!q.empty()) {
            string curr = q.front(); q.pop();
            for (char c : valid_chars) {
                string next = curr + c;
                if (next.length() > max_len) 
                    continue;
                if (check(next, s, k)) {
                    if (next.length() > res.length() || (next.length() == res.length() && next > res))
                        res = next;
                    q.push(next);
                }
            }
        }
        return res;
    }
};