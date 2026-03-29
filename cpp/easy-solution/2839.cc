/**
2839. Check if Strings Can be Made Equal With Operations I
    You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.
    You can apply the following operation on any of the two strings any number of times:
    Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
    Return true if you can make the strings s1 and s2 equal, and false otherwise.

    Example :
    Input: s1 = "abcd", s2 = "cdab"
    Output: true
    Explanation: We can do the following operations on s1:
    - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbad".
    - Choose the indices i = 1, j = 3. The resulting string is s1 = "cdab" = s2.
 */


#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<char> even_s1 = {s1[0], s1[2]};
        vector<char> even_s2 = {s2[0], s2[2]};
        
        vector<char> odd_s1 = {s1[1], s1[3]};
        vector<char> odd_s2 = {s2[1], s2[3]};
        
        sort(even_s1.begin(), even_s1.end());
        sort(even_s2.begin(), even_s2.end());
        
        sort(odd_s1.begin(), odd_s1.end());
        sort(odd_s2.begin(), odd_s2.end());
        
        return even_s1 == even_s2 && odd_s1 == odd_s2;
    }
};