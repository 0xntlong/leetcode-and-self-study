/*
3174. Clear Digits
    You are given a string s.
    Your task is to remove all digits by doing this operation repeatedly:
    Delete the first digit and the closest non-digit character to its left.
    Return the resulting string after removing all digits.

    Example :
    Input: s = "abc"
    Output: "abc"
    Explanation:
    There is no digit in the string.
*/


#include <string>
using namespace std;
class Solution {
    public:
        string clearDigits(string s) {
            string res;
            for (char c : s){
                if (isdigit(c)){
                    if (!res.empty()){
                        res.pop_back();
                    }
                } else {
                    res.push_back(c);
                }
            }
            return res;
        }
    };