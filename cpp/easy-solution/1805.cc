/*
1805. Number of Different Integers in a String
    You are given a string word that consists of digits and lowercase English letters.
    You will replace every non-digit character with a space. For example, "a123bc34d8ef34" will become " 123  34 8  34". Notice that you are left with some integers that are separated by at least one space: "123", "34", "8", and "34".
    Return the number of different integers after performing the replacement operations on word.
    Two integers are considered different if their decimal representations without any leading zeros are different.

    Example :
    Input: word = "a123bc34d8ef34"
    Output: 3
    Explanation: The three different integers are "123", "34", and "8". Notice that "34" is only counted once.
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;
class Solution {
public:
    int numDifferentIntegers(string word) {
        for (char& c : word){
            if (!isdigit(c))
                c = ' ';
        }
        set<string> Nums;
        string num = "";
        for (char& c : word){
            if (c == ' '){
                if (!num.empty()){
                    while (num.size() > 1 && num[0] == '0'){
                        num.erase(0, 1);
                    }
                    Nums.insert(num);
                    num = "";
                }
            } else {
                num += c;
            }
        }
        if (!num.empty()){
            while (num.size() > 1 && num[0] == '0'){
                num.erase(0, 1);
            }
            Nums.insert(num);
        }
        return Nums.size();
    }
};