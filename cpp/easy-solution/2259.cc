/*
2259. Remove Digit From Number ti Maximize Result
    You are given a string number representing a positive integer and a character digit.
    Return the resulting string after removing exactly one occurrence of digit from number such that the value of the resulting string in decimal form is maximized. The test cases are generated such that digit occurs at least once in number.

    Example :
    Input: number = "123", digit = "3"
    Output: "12"
    Explanation: There is only one '3' in "123". After removing '3', the result is "12".
*/

#include <string>
using namespace std;
class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        int i = n - 1;
        string res = number, temp = "";
        while ( i >= 0){
            if (number[i] == digit){
                res.erase(res.begin() + i);
                if (temp < res){
                    temp = res;
                }
                res = number;
            }
            i--;
        }
        return temp;
    }
};