/*
1370. Increasing Decreasing String
    You are given a string s. Reorder the string using the following algorithm:
    Remove the smallest character from s and append it to the result.
    Remove the smallest character from s that is greater than the last appended character, and append it to the result.
    Repeat step 2 until no more characters can be removed.
    Remove the largest character from s and append it to the result.
    Remove the largest character from s that is smaller than the last appended character, and append it to the result.
    Repeat step 5 until no more characters can be removed.
    Repeat steps 1 through 6 until all characters from s have been removed.
    If the smallest or largest character appears more than once, you may choose any occurrence to append to the result.
    Return the resulting string after reordering s using this algorithm.

    Example:
    Input: s = "aaaabbbbcccc"
    Output: "abccbaabccba"
    Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
    After steps 4, 5 and 6 of the first iteration, result = "abccba"
    First iteration is done. Now s = "aabbcc" and we go back to step 1
    After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
    After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
*/

#include <string>
#include <map>
using namespace std;
class Solution {
public:
    string sortString(string s) {
        map<char, int> freqMap;
        for (char c : s){
            freqMap[c]++;
        }
        string res;
        while (!freqMap.empty()){
            for (auto i = freqMap.begin(); i != freqMap.end(); ){
                res += i -> first;
                i -> second--;
                if (i -> second == 0){
                    i = freqMap.erase(i);
                } else {
                    i++;
                }
            }
            for (auto i = freqMap.rbegin(); i != freqMap.rend(); ){
                res += i -> first;
                i -> second--;
                if (i -> second == 0){
                    i = map<char, int>::reverse_iterator(freqMap.erase(next(i).base()));
                } else {
                    i++;
                }
            }
        }
        return res;
    }
};