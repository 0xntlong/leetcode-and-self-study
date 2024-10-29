/*
1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
    Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.
    Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.
    A prefix of a string s is any leading contiguous substring of s.

    Example :
    Input: sentence = "i love eating burger", searchWord = "burg"
    Output: 4
    Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
*/

#include <string>
using namespace std;
class Solution {
public:
    bool fact(string t, string s){
        for (int i = 0; i < s.size(); i++){
            if (s[i] != t[i]){
                return false;
            }
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        int word = 0;
        for (int i = 0; i < sentence.size(); i++){
            string t = "";
            while ( i < sentence.size() && sentence[i] != ' '){
                t += sentence[i];
                i++;
            }
            word++;
            if (fact(t, searchWord)){
                return word;
            }
        }
        return -1;
    }
};