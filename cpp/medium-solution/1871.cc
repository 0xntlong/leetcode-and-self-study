/**
1871. Jump Game VII
    You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:
    i + minJump <= j <= min(i + maxJump, s.length - 1), and
    s[j] == '0'.
    Return true if you can reach index s.length - 1 in s, or false otherwise.
    Example :
    Input: s = "011010", minJump = 2, maxJump = 3
    Output: true
    Explanation:
    In the first step, move from index 0 to index 3. 
    In the second step, move from index 3 to index 5.
 */



#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1')
            return false;
        vector<bool> dp(n, false);
        dp[0] = true;
        int reach = 0;
        for (int i = 1; i < n; i++) {
            if (i - minJump >= 0) {
                reach += dp[i - minJump];
            }
            if (i - maxJump - 1 >= 0) {
                reach -= dp[i - maxJump - 1];
            }
            if (reach > 0 && s[i] == '0') {
                dp[i] = true;
            }
        }
        return dp[n - 1];
    }
};