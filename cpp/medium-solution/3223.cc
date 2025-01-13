/*
3223. Minimum Length of String After Operatons
    You are given a string s.
    You can perform the following process on s any number of times:
    Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
    Delete the closest character to the left of index i that is equal to s[i].
    Delete the closest character to the right of index i that is equal to s[i].
    Return the minimum length of the final string s that you can achieve.

    Example :
    Input: s = "abaacbcbb"
    Output: 5
    Explanation:
    We do the following operations:
    Choose index 2, then remove the characters at indices 0 and 3. The resulting string is s = "bacbcbb".
    Choose index 3, then remove the characters at indices 0 and 5. The resulting string is s = "acbcb".
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<int> freq(26, 0);
        for (char c : s){
            freq[c - 'a']++;
        }
        int count = 0;
        for(int i = 0; i < 26; i++)
            count += (freq[i] % 2 ? 1 : (freq[i] ? 2 : 0));
        return count;
    }
};