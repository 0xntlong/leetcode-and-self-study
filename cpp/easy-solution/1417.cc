/*
1417. Reformat The String
    You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
    You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.
    Return the reformatted string or return an empty string if it is impossible to reformat the string.

    Example :
    Input: s = "a0b1c2"
    Output: "0a1b2c"
    Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    string reformat(string s) {
        int alpha = 0;
        int digit = 0;
        string alphaStr = "";
        string digitStr = "";
        for (int i = 0; i < s.length(); i++){
            if (s[i] >= 'a' && s[i]<= 'z')
                alphaStr = alphaStr + s[i];
            else if(s[i] >= '0' && s[i] <= '9')
                digitStr = digitStr + s[i];
        }
        alpha = alphaStr.length();
        digit = digitStr.length();
        if(abs(alpha - digit) > 1)
            return "";
        if(alpha > digit){
            int i = 0, j = 0;
            string res = "";
            while ( i < alpha && j < digit){
                res = res + alphaStr[i] + digitStr[j];
                i++;
                j++;
            }
            res = res + alphaStr[i];
            return res;
        } 
        else {
            int i = 0, j = 0;
            string res = "";
            while ( i < alpha && j < digit){
                res = res + digitStr[i] + alphaStr[j];
                i++;
                j++;
            }
            if (digit != alpha)
                res = res + digitStr[i];
            return res;
        }
    }
};