/*
796. Rotate String
    Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
    A shift on s consists of moving the leftmost character of s to the rightmost position.
    For example, if s = "abcde", then it will be "bcdea" after one shift.

    Example :
    Input: s = "abcde", goal = "cdeab"
    Output: true
*/

#include <string>
using namespace std;

// FRIST APPROACH
class Solution {
public:
    bool rotateString(string s, string goal) {
        int sz = s.size(), p = 31, m = 1e9 + 7;
        if ( sz != goal.size())
            return false;
        long pows[sz], hash_s[sz], hash_g[sz];
        for (int i = 0; i < sz; i++){
            pows[i] = (i == 0) ? 1 : (pows[i -1] * p) % m;
            hash_s[i] = ((s[i] - 'a' + 1) * pows[i]) % m;
            if (i > 0)
                hash_s[i] = (hash_s[i] + hash_s[i -1]) % m;
            hash_g[i] = ((goal[i] - 'a' + 1) * pows[i]) % m;
            if (i > 0)
                hash_g[i] = (hash_g[i] + hash_g[i - 1]) % m;
        }
        for(int i = 0; i < sz; i++){
            if (i == 0){
                if (hash_s[sz - 1] == hash_g[sz - 1])
                    return true;
            }
            else {
                long s_first = (hash_s[i-1] * pows[sz -1]) % m;
                long s_second = (hash_s[sz - 1] - hash_s[i -1] + m) % m;
                s_second = (s_second * pows[sz - i - 1]) % m;
                int id_g = sz - i;
                long g_first = (hash_g[id_g-1] * pows[sz -1]) % m;
                long g_second = (hash_g[sz -1] - hash_g[id_g - 1] + m) % m;
                g_second = (g_second * pows[sz - id_g - 1]) % m;
                if ( s_first == g_second && s_second == g_first)
                    return true;
            }
        }
        return false;
    }
};


// SECOND APPROACH
class Solution {
public:
    bool recursion( string s, string goal, int n){
        if (s == goal)
            return true;
        else if ( n == s.length())
            return false;
        else 
            return recursion(s.substr(1) + s[0], goal, n + 1);
    }
    bool rotateString(string s, string goal) {
        return recursion(s,goal, 0);
    }
};