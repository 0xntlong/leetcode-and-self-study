/**
2048. Next Greater Numerically Balanced Number
    An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
    Given an integer n, return the smallest numerically balanced number strictly greater than n.

    Example :
    Input: n = 1
    Output: 22
    Explanation: 
    22 is numerically balanced since:
    - The digit 2 occurs 2 times. 
    It is also the smallest numerically balanced number strictly greater than 1.
 */

class Solution {
public:
    int balance(int n){
        string s = to_string(n);
        int freq[10] = {0};
        for (char c : s) 
            freq[c - '0']++;

        for (char c : s) {
            int digit = c - '0';
            if (freq[digit] != digit)
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        n++;
        while (!balance(n)){
            n++;
        }
        return n;
    }
};