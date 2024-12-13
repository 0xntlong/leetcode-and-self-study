/*
2042. Check if Numbers Are Ascending in a Sentence
    A sentence is a list of tokens separated by a single space with no leading or trailing spaces. Every token is either a positive number consisting of digits 0-9 with no leading zeros, or a word consisting of lowercase English letters.
    For example, "a puppy has 2 eyes 4 legs" is a sentence with seven tokens: "2" and "4" are numbers and the other tokens such as "puppy" are words.
    Given a string s representing a sentence, you need to check if all the numbers in s are strictly increasing from left to right (i.e., other than the last number, each number is strictly smaller than the number on its right in s).
    Return true if so, or false otherwise.

    Example :
    example-1
    Input: s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
    Output: true
    Explanation: The numbers in s are: 1, 3, 4, 6, 12.
    They are strictly increasing from left to right: 1 < 3 < 4 < 6 < 12.
*/

#include <string>
using namespace std;
class Solution {
public:
    bool areNumbersAscending(string s) {
        int k = INT_MIN;
        for (int i = 0; i < s.length(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                int x = 0, y = i;
                while (s[y] >= '0' && s[y] <= '9' && y < s.length()){
                    x = x * 10 + (s[y] - '0');
                    y++;
                } if (x > k){
                    k = x;
                } else {
                    return false;
                }
                i = y;
            }
        }
        return true;
    }
};