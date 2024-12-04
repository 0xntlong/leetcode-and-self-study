/*
1897. Redistribute Characters to Make All Strings Equal
    You are given an array of strings words (0-indexed).
    In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, and move any character from words[i] to any position in words[j].
    Return true if you can make every string in words equal using any number of operations, and false otherwise.

    Example :
    Input: words = ["abc","aabc","bc"]
    Output: true
    Explanation: Move the first 'a' in words[1] to the front of words[2],
    to make words[1] = "abc" and words[2] = "abc".
    All the strings are now equal to "abc", so return true.
*/
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26);
        for (auto &word : words){
            for (char c : word){
                freq[c - 'a']++;
            }
        }
        int sz = words.size();
        for (int idx = 0; idx < 26; idx++){
            if (freq[idx] && freq[idx] % sz != 0)
                return false;
        }
        return true;
    }
};