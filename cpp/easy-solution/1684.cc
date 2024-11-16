/*
1684. Count the Number of Consistent Strings
    You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
    Return the number of consistent strings in the array words.

    Example:
    Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
    Output: 2
    Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int hashSet[26]={0};
        int c = 0;
        
        for (int i = 0; i < allowed.length(); i++){
            hashSet[allowed[i] - 'a']++;
        }
        for (int i = 0; i < words.size(); i++){
            string ans = words[i];
            bool count = true;
            for(int j=0; j < ans.length(); j++){
                if(hashSet[ans[j]-'a'] == 0){
                    count = false;
                    break;
                }
            }
            if (count){
                c++;
            }
        }
        return c;
    }
};