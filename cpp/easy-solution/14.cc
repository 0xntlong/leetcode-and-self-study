/*
14. Longest Common Prefix
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
    
    Example:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs.back(), ans = "";
        for (int i = 0; i < min(first.size(), last.size()); ++i) {
            if (first[i] != last[i]) return ans;
            ans += first[i];
        }
        return ans;
    }
};