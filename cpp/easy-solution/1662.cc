/*
1662. Check If Two String Arrays are Equivalent
    Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
    A string is represented by an array if the array elements concatenated in order forms the string.

    Example :
    Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
    Output: true
    Explanation:
    word1 represents string "ab" + "c" -> "abc"
    word2 represents string "a" + "bc" -> "abc"
    The strings are the same, so return true.
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;
        for (string & s : word1){
            for (char & c : s){
                if (i == word2.size() or word2[i][j] != c)
                    return false;
                j++;
                if ( j == word2[i].size()){
                    i++;
                    j = 0;
                }
            }
        }
        return i == word2.size();
    }
};