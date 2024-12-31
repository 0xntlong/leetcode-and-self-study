/*
2309. Greatest English Letter in Upper and Lower Case
    Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.
    An English letter b is greater than another letter a if b appears after a in the English alphabet.
    Example::
    Input: s = "lEeTcOdE"
    Output: "E"
    Explanation:
    The letter 'E' is the only letter to appear in both lower and upper case.
*/

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string greatestLetter(string s) {
        string ans = "";
        vector<int>freqlower(26, 0);
        vector<int>frequpper(26, 0);
        for (int i = 0; i < s.size(); i ++){
            int idx;
            if (s[i] >= 'a' && s[i] <= 'z'){
                idx = int(s[i] - 'a');
                freqlower[idx]++;
            } else {
                idx = int(s[i] - 'A');
                frequpper[idx]++;
            }
        }
        for (int i = 25; i >= 0; i--){
            if(frequpper[i] > 0 && freqlower[i] > 0){
                ans = char(i + 'A');
                break;
            }
        }
        return ans;
    }
};