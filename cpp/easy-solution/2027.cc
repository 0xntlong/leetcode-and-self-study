/*
2027. Minimum Moves to Convert String
    You are given a string s consisting of n characters which are either 'X' or 'O'.
    A move is defined as selecting three consecutive characters of s and converting them to 'O'. Note that if a move is applied to the character 'O', it will stay the same.
    Return the minimum number of moves required so that all the characters of s are converted to 'O'.

    Example :
    Input: s = "XXX"
    Output: 1
    Explanation: XXX -> OOO
    We select all the 3 characters and convert them in one move.
*/

#include <string>
using namespace std;
class Solution {
public:
    int minimumMoves(string s) {
        int i = 0;
        int n = s.length();
        int count = 0;
        while (i < n){
            if (s[i] == 'X'){
                s[i] = '0';
                count++;
                i += 3;
            } else {
                i++;
            }
        }
        return count;
    }
};