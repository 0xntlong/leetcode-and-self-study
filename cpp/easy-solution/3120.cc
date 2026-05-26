/**
3120. Count the Number of Special Characters I
    You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
    Return the number of special letters in word.
    Example :
    Input: word = "aaAbcBC"
    Output: 3
    Explanation:
    The special characters in word are 'a', 'b', and 'c'.
 */


#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower;
        unordered_set<char> upper;
        for (char c : word) {
            if (islower(c)) {
                lower.insert(c);
            } else {
                upper.insert(tolower(c));
            }
        }
        int ans = 0;
        for (char c : lower) {
            if (upper.count(c)) {
                ans++;
            }
        }
        return ans;
    }
};