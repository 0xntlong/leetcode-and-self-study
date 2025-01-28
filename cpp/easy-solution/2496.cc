/*
2496. Maximum Value of a String in an Array
    The value of an alphanumeric string can be defined as:
    The numeric representation of the string in base 10, if it comprises of digits only.
    The length of the string, otherwise.
    Given an array strs of alphanumeric strings, return the maximum value of any string in strs.

    Example :
    Input: strs = ["alic3","bob","3","4","00000"]
    Output: 5
    Explanation: 
    - "alic3" consists of both letters and digits, so its value is its length, i.e. 5.
    - "bob" consists only of letters, so its value is also its length, i.e. 3.
    - "3" consists only of digits, so its value is its numeric equivalent, i.e. 3.
    - "4" also consists only of digits, so its value is 4.
    - "00000" consists only of digits, so its value is 0.
    Hence, the maximum value is 5, of "alic3".
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int Value(string s){
        int count = 0, i = 0;
        while (i < s.size()){
            if (s[i] < '0' || s[i] > '9')
                return s.size();
            count = count * 10 + s[i++] - '0';
        }
        return count;
    }
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (auto s : strs)
            ans = max(ans, Value(s));
        return ans;
    }
};