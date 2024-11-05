/*
1556. Thousand Separator
    Given an integer n, add a dot (".") as the thousands separator and return it in string format.
    
    Example 1:
    Input: n = 987
    Output: "987"
    
    Example 2:
    Input: n = 1234
    Output: "1.234"
*/

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string thousandSeparator(int n) {
        string ans = to_string(n);
        if (ans.size() <= 3)
            return ans;
        for (int i = ans.size(); i >= 1; i = i - 3){
            if ( i == ans.size())
                continue;
            else ans.insert(i, ".");
        }
        return ans;
    }
};