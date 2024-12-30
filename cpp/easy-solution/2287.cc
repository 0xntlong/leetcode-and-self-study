/*
2287. Rearrange Characters to Make Target String
    You are given two 0-indexed strings s and target. You can take some letters from s and rearrange them to form new strings.
    Return the maximum number of copies of target that can be formed by taking letters from s and rearranging them.

    Example :
    Input: s = "ilovecodingonleetcode", target = "code"
    Output: 2
    Explanation:
    For the first copy of "code", take the letters at indices 4, 5, 6, and 7.
    For the second copy of "code", take the letters at indices 17, 18, 19, and 20.
    The strings that are formed are "ecod" and "code" which can both be rearranged into "code".
    We can make at most two copies of "code", so we return 2.
*/

#include <vector>
using namespace std;
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> freq(26, 0);
        for (auto c : s){
            int i = c - 'a';
            freq[i]++;
        }
        for (int cnt = 0; true; cnt++){
            for (char c : target){
                int i = c - 'a';
                freq[i]--;
                if (freq[i] < 0)
                    return cnt;
            }
        }
        return 1;
    }
};