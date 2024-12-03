/*
2109. Adding Spaces to String
    You are given a 0-indexed string s and a 0-indexed integer array spaces that describes the indices in the original string where spaces will be added. Each space should be inserted before the character at the given index.
    For example, given s = "EnjoyYourCoffee" and spaces = [5, 9], we place spaces before 'Y' and 'C', which are at indices 5 and 9 respectively. Thus, we obtain "Enjoy Your Coffee".
    Return the modified string after the spaces have been added.
    
    Example :
    Input: s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
    Output: "Leetcode Helps Me Learn"
    Explanation: 
    The indices 8, 13, and 15 correspond to the underlined characters in "LeetcodeHelpsMeLearn".
    We then place spaces before those characters.
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        const int m = s.size(), n = spaces.size();
        string newStr(m + n, ' ');
        int j = 0;
        for (int i = 0; i < m; i++){
            if (j < n && i == spaces[j]){
                newStr[i + j] = ' ';
                j++;
            }
            newStr[i + j] = s[i];
        }
        return newStr;

    }
};