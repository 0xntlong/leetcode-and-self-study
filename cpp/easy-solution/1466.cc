/*
1446. Consecutive Characters
    The power of the string is the maximum length of a non-empty substring that contains only one unique character.
    Given a string s, return the power of s.

    Example :
    Input: s = "leetcode"
    Output: 2
    Explanation: The substring "ee" is of length 2 with the character 'e' only.
*/

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        if (s.length() == 1){
            return 1;
        }
        int count = 1;
        int maximum = 0;
        for (int i = 1; i < s.length(); i++){
            if (s[i] == s[i - 1]){
                count++;
            } else {
                maximum = max(count, maximum);
                count = 1;
            }
        }
        return (count < maximum) ? maximum : count;
    }
};