/**
67. Add Binary
    Given two binary strings a and b, return their sum as a binary string.

    Example :
    Input: a = "11", b = "1"
    Output: "100"
 */

#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int total = carry;

            if (i >= 0) 
                total += a[i--] - '0';
            if (j >= 0) 
                total += b[j--] - '0';

            res.push_back((total % 2) + '0');
            carry = total / 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};