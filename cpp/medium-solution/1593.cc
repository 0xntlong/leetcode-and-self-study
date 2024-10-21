/*
1593. Split a String Into the Max Number of Unique Substrings
    Given a string s, return the maximum number of unique substrings that the given string can be split into.
    You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.
    A substring is a contiguous sequence of characters within a string.

    Example:
    Input: s = "ababccc"
    Output: 5
    Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
*/

#include <string>
#include <unordered_set>
using namespace std; 
class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> hash_set;
        return DFS(0, s, hash_set);
    }

private:
    int DFS(int i, const string& s, unordered_set<string> hash_set){
        if ( i == s.length()){
            return 0;
        }
        int result = 0;
        string cur_substr = "";
        for (int j = i ; j < s.length(); j++){
            cur_substr += s[j];
            if (hash_set.find(cur_substr) == hash_set.end()){
                hash_set.insert(cur_substr);
                result = max(result, 1 + DFS(j + 1, s , hash_set));
                hash_set.erase(cur_substr);
            }
        }
        return result;
    }
};