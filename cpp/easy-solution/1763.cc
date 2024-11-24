/*
1763. Longest Nice Substring
    A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
    Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.

    Example :
    Input: s = "YazaAay"
    Output: "aAa"
    Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
    "aAa" is the longest nice substring.
*/


#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestNiceSubstring(string s) {
        string res = "";
        int len = s.length();
        for (int i = 0; i < (len - res.length()); i++){
            string temp = "";
            vector<bool>freq1(26, false);
            vector<bool>freq2(26, false);
            for (int j = i; j < len; j++){
                temp.push_back(s[j]);
                if (s[j] >= 'a' && s[j] <= 'z'){
                    freq1[s[j] - 'a'] = true;
                } else {
                    freq2[s[j] - 'A'] = true;
                }
                if (temp.length() > 1 && temp.length() > res.length()){
                    bool t = true;
                    for (int i = 0; i < 26; i++){
                        if (freq1[i] || freq2[i]){
                            if (!(freq1[i] && freq2[i])){
                                t = false;
                                break;
                            }
                        }
                    }
                    if (t) {
                        res = temp;
                    }
                }
            }
        }
        return res;
    }
};