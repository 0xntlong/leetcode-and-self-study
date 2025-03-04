/*
2609. Find the Longest Balanced Substring of a Binary String
    You are given a binary string s consisting only of zeroes and ones.
    A substring of s is considered balanced if all zeroes are before ones and the number of zeroes is equal to the number of ones inside the substring. Notice that the empty substring is considered a balanced substring.
    Return the length of the longest balanced substring of s.
    A substring is a contiguous sequence of characters within a string.
    Example :
    Input: s = "01000111"
    Output: 6
    Explanation: The longest balanced substring is "000111", which has length 6.
*/

#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
        int findTheLongestBalancedSubstring(string s) {
            string tmp = "01";
            while (s.find(tmp) != string::npos){
                tmp = "0" + tmp + "1";
            }
            return tmp.length() - 2;
        }
    };