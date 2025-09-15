/**
1935. Maximum Number of Words You Can Type
    There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.
    Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.
    Example :
    Input: text = "hello world", brokenLetters = "ad"
    Output: 1
    Explanation: We cannot type "world" because the 'd' key is broken.
 */


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>    
using namespace std;
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        int cnt = 0;
        for (auto& c : brokenLetters){
            st.insert(c);
        }
        stringstream ss(text);
        string word;
        vector<string> words;
        while (ss >> word){
            words.push_back(word);
        }
        for (auto w: words){
            for (char c : w){
                if (st.find(c) != st.end()){
                    cnt++;
                    break;
                }
            }
        }
        return words.size() - cnt;
    }
};