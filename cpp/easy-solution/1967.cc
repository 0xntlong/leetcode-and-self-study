/*
1967. Number of Strings That Appear as Substrings in Word
    Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.
    A substring is a contiguous sequence of characters within a string.

    Example :
    Input: patterns = ["a","abc","bc","d"], word = "abc"
    Output: 3
    Explanation:
    - "a" appears as a substring in "abc".
    - "abc" appears as a substring in "abc".
    - "bc" appears as a substring in "abc".
    - "d" does not appear as a substring in "abc".
    3 of the strings in patterns appear as a substring in word.
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int check; 
        int ans = 0;
        for (int i = 0; i < patterns.size(); i++){
            for (int j = 0; j < word.length(); j++){
                if (word[j] == patterns.at(i)[0]){
                    check = 1;
                    for (int k = 1; k < patterns.at(i).length(); k++){
                        if (patterns.at(i)[k] != word[j + k]){
                            check = 0;
                            break;
                        }
                    }
                    if (check == 1){
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};