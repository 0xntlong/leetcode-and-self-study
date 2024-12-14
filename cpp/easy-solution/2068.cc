/*
2068. Check Whether Two String are Almost Equivalent
    Two strings word1 and word2 are considered almost equivalent if the differences between the frequencies of each letter from 'a' to 'z' between word1 and word2 is at most 3.
    Given two strings word1 and word2, each of length n, return true if word1 and word2 are almost equivalent, or false otherwise.
    The frequency of a letter x is the number of times it occurs in the string.

    Example :
    Input: word1 = "aaaa", word2 = "bccb"
    Output: false
    Explanation: There are 4 'a's in "aaaa" but 0 'a's in "bccb".
    The difference is 4, which is more than the allowed 3.
*/

#include <string>
using namespace std;
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int count[26] = {};
        for (char c : word1){
            count[c - 'a']++;
        }
        for (char c : word2){
            count[c - 'a']--;
        }
        for (int i = 0; i < 26; i++){
            if (abs(count[i]) > 3)
                return false;
        }
        return true;
    }
};