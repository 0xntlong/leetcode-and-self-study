/*
2283. Check if Number Has Equal Digit Count and Digit Value
    You are given a 0-indexed string num of length n consisting of digits.
    Return true if for every index i in the range 0 <= i < n, the digit i occurs num[i] times in num, otherwise return false.

    Example :
    Input: num = "1210"
    Output: true
    Explanation:
    num[0] = '1'. The digit 0 occurs once in num.
    num[1] = '2'. The digit 1 occurs twice in num.
    num[2] = '1'. The digit 2 occurs once in num.
    num[3] = '0'. The digit 3 occurs zero times in num.
    The condition holds true for every index in "1210", so return true.
*/

#include <vector>
using namespace std;
class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();
        vector<int> freq(10, 0);
        for (char c : num){
            freq[c - '0']++;
        }
        for (int i = 0; i < n; i++){
            if (freq[i] != (num[i] - '0')){
                return false;
            }
        }
        return true;
    }
};