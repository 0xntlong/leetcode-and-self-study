/*
58. Length of Last Word
    Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.
    A word is a maximal substring consisting of non-space characters only.

    Example:
    Input: s = "Hello World"
    Output: 5
    Explanation: The last word is "World" with length 5.  
*/

#include<string>
using namespace std;
class Solution{
public:
    int lengthOfLastWord(string s){
        int count = 0;
        int i = s.length() -1;
        while (i >= 0 && s[i] == ' '){
            i--;
        }
        while (i >= 0 && s[i] != ' '){
            count++;
            i--;
        }
        return count;
    }
};