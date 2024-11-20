/*
2516. Take K of Each Character From Left and Right
    You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
    Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

    Example :
    Input: s = "aabaaaacaabc", k = 2
    Output: 8
    Explanation: 
    Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
    Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
    A total of 3 + 5 = 8 minutes is needed.
    It can be proven that 8 is the minimum number of minutes needed.
*/

#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        int ans = n;
        int a = 0, b = 0, c = 0;
        int countA = 0, countB = 0, countC = 0;
        for (char chr : s){
            if ( chr == 'a')
                countA++;
            else if ( chr == 'b')
                countB++;
            else if ( chr == 'c')
                countC++;
        }
        if ( countA < k || countB < k || countC < k){
            return -1;
        }
        a = 0, b = 0, c = 0;
        while (r < n){
            if (s[r] == 'a')
                a++;
            if (s[r] == 'b')
                b++;
            if (s[r] == 'c')
                c++;
            r++;
            while ( a > countA - k || b > countB - k || c > countC - k){
                if (s[l] == 'a')
                    a--;
                if (s[l] == 'b')
                    b--;
                if (s[l] == 'c')
                    c--;
                l++;
            }
            ans = min(ans, n - (r -l));
        }
        return ans;
    }
};