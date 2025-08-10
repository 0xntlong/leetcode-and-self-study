/**
869. Reordered Power of 2
    You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
    Return true if and only if we can do this so that the resulting number is a power of two.

    Example 1:
    Input: n = 1
    Output: true
 */


#include <algorithm>
#include <string>
using namespace std;
    
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        for (int i = 0; i < 31; i++){
            int power = 1 << i;
            string p = to_string(power);
            sort(p.begin(), p.end());
            if (s == p){
                return true;
            }
        }
        return false;
    }
};