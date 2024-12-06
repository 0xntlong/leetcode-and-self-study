/*
1941. Check if All Characters Have Equal Number of Occurrences
    Given a string s, return true if s is a good string, or false otherwise.
    A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
    
    Example :
    Input: s = "abacbc"
    Output: true
    Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
*/


#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> chr(26, 0);
        for (char c : s)
            chr[c - 'a']++;
        int freq = chr[s[0]-'a'];
        for (int i : chr){
            if (i != freq && i != 0)
                return false;
        }
        return true;
           
    }
};