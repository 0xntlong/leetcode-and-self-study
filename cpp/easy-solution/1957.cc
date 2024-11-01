/*
1957. Delete Characters to Make Fancy String
    A fancy string is a string where no three consecutive characters are equal.
    Given a string s, delete the minimum possible number of characters from s to make it fancy.
    Return the final string after the deletion. It can be shown that the answer will always be unique.

    Example:
    leeetcode"
    Output: "leetcode"
    Explanation:
    Remove an 'e' from the first group of 'e's to create "leetcode".
    No three consecutive characters are equal, so return "leetcode".
*/

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3){
            return s;
        }
        int j = 2;
        for (int i = 2; i < s.size(); i++)
            if ( s[i] != s[j -1] || s[i] != s[j-2] )
                s[j++] = s[i];
        s.resize(j);
        return s; 
    }
};