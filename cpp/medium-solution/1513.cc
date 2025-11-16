/**
1513. Number of Substrings With Only 1s
    Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.
    Example :
    Input: s = "0110111"
    Output: 9
    Explanation: There are 9 substring in total with only 1's characters.
    "1" -> 5 times.
    "11" -> 3 times.
    "111" -> 1 time.
 */


#include <string>
using namespace std;

class Solution {
public:
    int numSub(string s) {
        const long long mod = 1000000007;
        long long cnt = 0, curr = 0;
        for (char c : s){
            if (c == '1'){
                curr++;
            } else {
                cnt += curr * (curr + 1);
                curr = 0;
            }
        }
        cnt += curr * (curr + 1);
        return (cnt / 2) % mod;
    }
};