/*
1592. Rearrange Spaces Between Words
    You are given a string text of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by at least one space. It's guaranteed that text contains at least one word.
    Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent words and that number is maximized. If you cannot redistribute all the spaces equally, place the extra spaces at the end, meaning the returned string should be the same length as text.
    Return the string after rearranging the spaces.
    Example :

    Input: text = "  this   is  a sentence "
    Output: "this   is   a   sentence"
    Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.
*/

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    string reorderSpaces(string text) {
        int space = 0, i = 0, n = text.length();
        vector<string> words;
        string ans = "";
        while ( i < n ){
            string temp = "";
            while (i < n && text[i] == ' '){
                space++;
                i++;
            }
            while ( i < n && text[i] != ' '){
                temp += text[i];
                i++;
            }
            if( !temp.empty()){
                words.push_back(temp);
            }
        }
        if (words.size() == 1){
            ans += words[0];
            ans += string(space, ' ');
            return ans;
        }
        int k = space / (words.size() - 1);
        int remain = space % (words.size() - 1);
        for (int j = 0; j < words.size(); j++){
            ans += words[j];
            if ( j + 1 != words.size()){
                ans += string(k, ' ');
            }
        }
        ans += string(remain, ' ');
        return ans;
    }
};