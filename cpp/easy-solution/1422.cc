/*
1422. Maximum Score After Splitting a String
    Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).
    The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

    Example :
    Input: s = "011101"
    Output: 5 
    Explanation: 
    All possible ways of splitting s into two non-empty substrings are:
    left = "0" and right = "11101", score = 1 + 4 = 5 
    left = "01" and right = "1101", score = 1 + 3 = 4 
    left = "011" and right = "101", score = 1 + 2 = 3 
    left = "0111" and right = "01", score = 1 + 1 = 2 
    left = "01110" and right = "1", score = 2 + 1 = 3
*/

#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxScore(string s) {
        int one = 0, zero = 0, result = 0, m= INT_MIN;
        for (int i = 0; i < s.length(); i++){
            result += s[i] - '0';
        }
        if (result == 0){
            return s.length() -1;
        }
        for (int i = 0; i < s.length() - 1; i++){
            if (s[i] == '0'){
                zero++;
            }
            else {
                one++;
            }
            m = max(m, ((result - one) + zero));
        }
        return m;
    }
};