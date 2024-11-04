/*
1544. Make The String Great
    Given a string s of lower and upper case English letters.
    A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
    0 <= i <= s.length - 2
    s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
    To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.
    Return the string after making it good. The answer is guaranteed to be unique under the given constraints.
    Notice that an empty string is also good.

    Example :
    Input: s = "leEeetcode"
    Output: "leetcode"
    Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
*/


#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string ans = string(1, s[0]);
        for(int i = 1; i < n; i++){
            if (!ans.empty() && s[i] != ans.back()
            && (s[i] & 31) == (ans.back() & 31))
                ans.pop_back();
            else 
                ans.push_back(s[i]);
        }
        return ans;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();