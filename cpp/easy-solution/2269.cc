/*
2269. Find the K-Beaty of a Number
    The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:
    It has a length of k.
    It is a divisor of num.
    Given integers num and k, return the k-beauty of num.
    Note:
    Leading zeros are allowed.
    0 is not a divisor of any value.
    A substring is a contiguous sequence of characters in a string.

    Example :
    Input: num = 240, k = 2
    Output: 2
    Explanation: The following are the substrings of num of length k:
    - "24" from "240": 24 is a divisor of 240.
    - "40" from "240": 40 is a divisor of 240.
    Therefore, the k-beauty is 2.
*/

#include <string>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int res = 0;
        string numStr = to_string(num);
        int n = numStr.size();
        for (int i = 0 ; i <= n - k; i++){
            string subStr = numStr.substr(i, k);
            int divisor = stoi(subStr);
            if (divisor != 0 && num % divisor == 0){
                res++;
            }
        }
        return res;
    }
};