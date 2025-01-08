/*
3042. Count Prefix and Subffix Pairs I
    You are given a 0-indexed string array words.
    Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:
        + isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix of str2, and false otherwise.
    For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.
    Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.
    Example :
    Input: words = ["a","aba","ababa","aa"]
    Output: 
    Explanation: In this example, the counted index pairs are:
    i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
    i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
    i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
    i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
    Therefore, the answer is 4.
*/

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2){
        int n = str1.size(), m = str2.size();
        if (n > m)
            return false;
        return str2.substr(0, n) == str1 && str2.substr(m - n, n) == str1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (isPrefixAndSuffix(words[i], words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};