/*
2047. Number of Valid Words in a Sentence
    A sentence consists of lowercase letters ('a' to 'z'), digits ('0' to '9'), hyphens ('-'), punctuation marks ('!', '.', and ','), and spaces (' ') only. Each sentence can be broken down into one or more tokens separated by one or more spaces ' '.
    A token is a valid word if all three of the following are true:
    It only contains lowercase letters, hyphens, and/or punctuation (no digits).
    There is at most one hyphen '-'. If present, it must be surrounded by lowercase characters ("a-b" is valid, but "-ab" and "ab-" are not valid).
    There is at most one punctuation mark. If present, it must be at the end of the token ("ab,", "cd!", and "." are valid, but "a!b" and "c.," are not valid).
    Examples of valid words include "a-b.", "afad", "ba-c", "a!", and "!".
    Given a string sentence, return the number of valid words in sentence.

    Example :
    Input: sentence = "cat and  dog"
    Output: 3
    Explanation: The valid words in the sentence are "cat", "and", and "dog".
*/

#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
    int countValidWords(string sentence) {
        istringstream iss(sentence);
        string token;
        int validCount = 0;
        while (iss >> token){
            if (IsValid(token)){
                validCount++;
            }
        }
        return validCount;
    }

private:
    bool IsValid(const string& n){
        int count = 0;
        int valid = 0;
        for (size_t i = 0; i < n.size(); i++){
            char c = n[i];
            if (isdigit(c)){
                return false;
            }
            if (c == '-'){
                count++;
                if (count > 1 || i == 0 || i == n.size() - 1 || !islower(n[i - 1]) || !islower(n[i + 1])){
                    return false;
                }
            }
            if (c == '!' || c == '.' || c == ','){
                valid++;
                if (valid > 1 || i != n.size() - 1){
                    return false;
                }
            }
        }
        return true;
    }
};