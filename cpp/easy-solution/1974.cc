/*
1974. Minimum Time to Type Word Using Special Typewriter
    There is a special typewriter with lowercase English letters 'a' to 'z' arranged in a circle with a pointer. A character can only be typed if the pointer is pointing to that character. The pointer is initially pointing to the character 'a'.
    Each second, you may perform one of the following operations:
    Move the pointer one character counterclockwise or clockwise.
    Type the character the pointer is currently on.
    Given a string word, return the minimum number of seconds to type out the characters in word.

    Example :
    Input: word = "abc"
    Output: 5
    Explanation: 
    The characters are printed as follows:
    - Type the character 'a' in 1 second since the pointer is initially on 'a'.
    - Move the pointer clockwise to 'b' in 1 second.
    - Type the character 'b' in 1 second.
    - Move the pointer clockwise to 'c' in 1 second.
    - Type the character 'c' in 1 second.
*/

#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int minTimeToType(string word) {
        unordered_map<char, int> map;
        int k = 0;
        for (char i = 'a'; i <= 'z'; i++){
            map[i] = k;
            k++;
        }
        int ans = 0;
        int time = abs(map['a'] - map[word[0]]);
        ans = ans + min(time, 26 - time) + 1;
        for (int j = 1; j < word.length(); j++){
            int time = abs(map[word[j - 1]] - map[word[j]]);
            ans = ans + min(time, 26 - time) + 1;
        }
        return ans;
    }
};