/*
2129. Capitalize the Title 
    You are given a string title consisting of one or more words separated by a single space, where each word consists of English letters. Capitalize the string by changing the capitalization of each word such that:
    If the length of the word is 1 or 2 letters, change all letters to lowercase.
    Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
    Return the capitalized title.

    Example :
    Input: title = "capiTalIze tHe titLe"
    Output: "Capitalize The Title"
    Explanation:
    Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.
*/

#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
    string capitalizeTitle(string title){
        for (char& c : title){
            c = tolower(c);
        }
        stringstream ss(title);
        string word, result;
        while (ss >> word){
            if (word.length() <= 2){
                result += word + " ";
            } else {
                word[0] = toupper(word[0]);
                result += word + " ";
            }
        }
        if (!result.empty()){
            result.pop_back();
        }
        return result;
    }
};