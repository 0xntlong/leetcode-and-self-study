/*
2255. Count Prefixes of a Given String
    You are given a string array words and a string s, where words[i] and s comprise only of lowercase English letters.
    Return the number of strings in words that are a prefix of s.

    A prefix of a string is a substring that occurs at the beginning of the string. A substring is a contiguous sequence of characters within a string.

    Example :
    Input: words = ["a","b","c","ab","bc","abc"], s = "abc"
    Output: 3
    Explanation:
    The strings in words which are a prefix of s = "abc" are:
    "a", "ab", and "abc".
    Thus the number of strings in words which are a prefix of s is 3.
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int prefixCount = 0;
        for (string word : words){
            if (word == s.substr(0, word.size())){
                prefixCount++;
            }
        }
        return prefixCount;
    }
};