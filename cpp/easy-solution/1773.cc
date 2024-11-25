/*
1773. Count Items Matching a Rule
    You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.
    The ith item is said to match the rule if one of the following is true:
    ruleKey == "type" and ruleValue == typei.
    ruleKey == "color" and ruleValue == colori.
    ruleKey == "name" and ruleValue == namei.
    Return the number of items that match the given rule.

    Example :
    Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
    Output: 1
    Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0, i = 0, j = 0;
        int size = items.size();
        if ( ruleKey == "type"){
            j = 0;
            for ( i = 0; i < size; i++){
                if (items[i][j] == ruleValue){
                    count++;
                }
            }
        }
        if (ruleKey == "color"){
            j = 1;
            for ( i = 0; i < size; i++){
                if (items[i][j] == ruleValue){
                    count++;
                }
            }
        }
        if (ruleKey == "name"){
            j = 2;
            for ( i = 0; i < size; i++){
                if (items[i][j] == ruleValue){
                    count++;
                }
            }
        }
        return count++;
    }
};