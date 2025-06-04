/*
3403. Find the Lexicographically Largest String From the Box I
    You are given a string word, and an integer numFriends.
    Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:
    word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
    All the split words are put into a box.
    Find the lexicographically largest string from the box after all the rounds are finished.

    Example :
    Input: word = "dbca", numFriends = 2
    Output: "dbc"
    Explanation: 
    All possible splits are:
    "d" and "bca".
    "db" and "ca".
    "dbc" and "a".
 */


class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1)
            return word;
        int n = word.size();
        int m = n - numFriends + 1;
        int i = 0, j = 1;
        while (j < n){
            int k = 0;
            while (j + k < n && word[i + k] == word[j + k]){
                k++;
            }
            if (j + k < n && word[i + k] < word[j + k]){
                i = exchange(j, max(j + 1, i + k + 1));
            } else {
                j += k + 1;
            }
        }
        string s = word.substr(i);
        return s.size() <= m ? s : s.substr(0, m);
    }
};