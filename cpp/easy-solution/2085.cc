/*
2085. Count Common Words With One Occurrence
    Given two string arrays words1 and words2, return the number of strings that appear exactly once in each of the two arrays.

    Example :
    Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
    Output: 2
    Explanation:
    - "leetcode" appears exactly once in each of the two arrays. We count this string.
    - "amazing" appears exactly once in each of the two arrays. We count this string.
    - "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
    - "as" appears once in words1, but does not appear in words2. We do not count this string.
    Thus, there are 2 strings that appear exactly once in each of the two arrays.
*/

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> hashmap;
        int count = 0;
        for (auto& i : words1)
            hashmap[i]++;
        for (auto& i : words2){
            auto freq = hashmap.find(i);
            if (freq == hashmap.end())
                continue;
            if (freq -> second < 2)
                freq->second--;
            if (freq -> second == 0)
                count++;
            else if(freq -> second == -1)
                count--;
        }
        return count--;
    }
};