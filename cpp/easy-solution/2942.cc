/*
2942. Find Words Containing a Character
    You are given a 0-indexed array of strings words and a character x.
    Return an array of indices representing the words that contain the character x.
    Note that the returned array may be in any order.

    Example :
    Input: words = ["leet","code"], x = "e"
    Output: [0,1]
    Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.
 */

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        const int n = words.size();
        vector<int> res;
        for (int i = 0; i < n; i++){
            if (words[i].find(x) != -1){
                res.push_back(i);
            }
        }
        return res;
    }
};