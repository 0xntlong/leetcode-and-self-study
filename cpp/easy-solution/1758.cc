/*
1758. Minimum Changes To Make Alternating Binary String
    You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.
    The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.
    Return the minimum number of operations needed to make s alternating.

    Example:
    Input: s = "0100"
    Output: 1
    Explanation: If you change the last character to '1', s will be "0101", which is alternating.
*/

#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        int zero = 0;
        int one = 0;
        for (int i = 0; i < s.length(); i++){
            if ((i % 2 == 0 && s[i] != '0') || (i % 2 != 0 && s[i] != '1')){
                zero += 1;
            }
            if ((i % 2 == 0 && s[i] != '1') || (i % 2 != 0 && s[i] != '0')){
                one += 1;
            }
        }
        return std::min(zero, one);
    }
};