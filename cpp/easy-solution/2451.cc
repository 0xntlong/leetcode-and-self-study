/*
2451. Odd String Difference 
    You are given an array of equal-length strings words. Assume that the length of each string is n.
    Each string words[i] can be converted into a difference integer array difference[i] of length n - 1 where difference[i][j] = words[i][j+1] - words[i][j] where 0 <= j <= n - 2. Note that the difference between two letters is the difference between their positions in the alphabet i.e. the position of 'a' is 0, 'b' is 1, and 'z' is 25.
    For example, for the string "acb", the difference integer array is [2 - 0, 1 - 2] = [2, -1].
    All the strings in words have the same difference integer array, except one. You should find that string.
    Return the string in words that has different difference integer array.

    Example :
    Input: words = ["adc","wzy","abc"]
    Output: "abc"
    Explanation: 
    - The difference integer array of "adc" is [3 - 0, 2 - 3] = [3, -1].
    - The difference integer array of "wzy" is [25 - 22, 24 - 25]= [3, -1].
    - The difference integer array of "abc" is [1 - 0, 2 - 1] = [1, 1]. 
    The odd array out is [1, 1], so we return the corresponding string, "abc".
*/


#include <vector>
#include<string>
using namespace std;
class Solution {
public:
    string oddString(vector<string>& words) {
        vector<int>diff1, diff2;
        for (int i = 1; i < words[0].size(); i++){
            diff1.push_back(words[0][i] - words[0][i - 1]);
            diff2.push_back(words[1][i] - words[1][i - 1]);
        }
        if (diff1 == diff2){
            for (int i = 2; i < words.size(); i++){
                vector<int> currDiff;
                for (int j = 1; j < words[i].size(); j++){
                    currDiff.push_back(words[i][j] - words[i][j - 1]);
                }
                if (currDiff != diff1){
                    return words[i];
                }
            }
        }
        vector<int>diff3;
        for (int i = 1; i < words[2].size(); i++){
            diff3.push_back(words[2][i] - words[2][i - 1]);
        }
        return (diff1 == diff3) ? words[1] : words[0];
    }
};