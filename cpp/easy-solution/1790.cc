/*
1790. Check if One String Swap Can Make Strings Equal
    You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
    Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

    Example :
    Input: s1 = "bank", s2 = "kanb"
    Output: true
    Explanation: For example, swap the first character with the last character of s2 to make "bank".
*/

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> isgood (n, 1);
        for (auto& edge : edges){
            isgood[edge[1]] = 0;
        }
        int champion = -1;
        for (int i = 0; i < n; i++){
            if (isgood[i]){
                if (champion != -1){
                    return -1;
                }
                champion = i;
            }
        }
        return champion;
    }
};