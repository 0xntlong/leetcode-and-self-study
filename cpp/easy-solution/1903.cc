/*
1903. Largest Odd Number in String
    You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
    A substring is a contiguous sequence of characters within a string.

    Example :
    Input: num = "52"
    Output: "5"
    Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
*/

#include <string>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        if (num.back() % 2 == 1)
            return num;
        int n = num.length() - 1;
        while (n >= 0){
            int i = num[n];
            if ( i % 2 == 1)
                return num.substr(0, n + 1);
            n--;
        }
        return "";
    }
};