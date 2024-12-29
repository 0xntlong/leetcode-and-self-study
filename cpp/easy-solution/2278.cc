/*
2278. Percentage of Letters in a String
    Given a string s and a character letter, return the percentage of characters in s that equal letter rounded down to the nearest whole percent.

    Example :
    Input: s = "foobar", letter = "o"
    Output: 33
    Explanation:
    The percentage of characters in s that equal the letter 'o' is 2 / 6 * 100% = 33% when rounded down, so we return 33.
*/

#include <string>
using namespace std;
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        int n = s.size();
        for (char c : s){
            if (c == letter){
                count++;
            }
        }
        return (count * 100) / n;
    }
};