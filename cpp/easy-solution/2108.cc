/*
2108. Find First Palindromic String in the Array
    Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".
    A string is palindromic if it reads the same forward and backward.
    
    xample :
    Input: words = ["abc","car","ada","racecar","cool"]
    Output: "ada"
    Explanation: The first string that is palindromic is "ada".
    Note that "racecar" is also palindromic, but it is not the first.
*/

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool is_Palindrome(const string& str){
        int left = 0, right = str.size() - 1;
        while (left < right){
            if (str[left] != str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (const string& word : words){
            if (is_Palindrome(word)){
                return word;
            }
        }
        return "";
    }
};