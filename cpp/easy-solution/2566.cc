/*
2566. Maximum Difference by Remapping a Digit
    You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.
    Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.
    Notes:
    When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
    Bob can remap a digit to itself, in which case num does not change.
    Bob can remap different digits for obtaining minimum and maximum values respectively.
    The resulting number after remapping can contain leading zeroes.

    Example:
    Input: num = 11891
    Output: 99009
    Explanation: 
    To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
    To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
    The difference between these two numbers is 99009.
*/


#include <string>
using namespace std;

class Solution {
    public:
        int minMaxDifference(int num) {
            string s = to_string(num);
            for (int i = 0; i < s.length(); i++){
                if (s[i] < '9'){
                    for (int j = i + 1; j < s.length(); j++){
                        if (s[i] == s[j]){
                            s[j] = '9';
                        }
                    }
                    s[i] = '9';
                    break;
                }
            }
            int max = stoi(s);
            s = to_string(num);
            for (int i = 0; i < s.length(); i++){
                if (s[i] > '0'){
                    for (int j = i + 1; j < s.length(); j++){
                        if (s[i] == s[j]){
                            s[j] = '0';
                        }
                    }
                    s[i] = '0';
                    break;
                }
            }
            return max - stoi(s);
        }
    };