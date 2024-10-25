/*
1408. String Matching in an Array
    Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.
    A substring is a contiguous sequence of characters within a string

    Example :
    Input: words = ["mass","as","hero","superhero"]
    Output: ["as","hero"]
    Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
    ["hero","as"] is also a valid answer.
*/


#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>result;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if (i != j){
                    if(words[j].find(words[i]) != string::npos){
                        result.push_back(words[i]);
                        break;
                    } 
                }
            }
        }
        return result;
    }
};