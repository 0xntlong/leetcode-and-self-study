/**
1189. Maximum Number of Balloons
    Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
    You can use each character in text at most once. Return the maximum number of instances that can be formed.

    Example :
    Input: text = "nlaebolko"
    Output: 1
 */


 
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);
        for (char c : text) {
            freq[c - 'a']++;
        }
        int count_b = freq['b' - 'a'];
        int count_a = freq['a' - 'a'];
        int count_l = freq['l' - 'a'] / 2;
        int count_o = freq['o' - 'a'] / 2;
        int count_n = freq['n' - 'a'];
        return min({count_b, count_a, count_l, count_o, count_n});
    }
};