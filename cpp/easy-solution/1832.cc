/*
1832. Check if the Sentence Is Pangram
    A pangram is a sentence where every letter of the English alphabet appears at least once.
    Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

    Example :
    Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
    Output: true
    Explanation: sentence contains at least one of every letter of the English alphabet.
*/

#include <string> 
#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> arr(26, 0);
        int count = 0;
        for (char& c : sentence){
            int idx = c - 'a';
            if (arr[idx] == 0){
                arr[idx]++;
                count++;
            }
        }
        return true ? (count == 26) : false;
    }
};