/*
2434. Using a Robot to Print the Lexicographically Smallest String
    You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:
    Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
    Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
    Return the lexicographically smallest string that can be written on the paper.

    Example :
    Input: s = "zza"
    Output: "azz"
    Explanation: Let p denote the written string.
    Initially p="", s="zza", t="".
    Perform first operation three times p="", s="", t="zza".
    Perform second operation three times p="azz", s="", t="".
 */

#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> min_char(n);
        min_char[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--){
            min_char[i] = min(s[i], min_char[i + 1]);
        }
        vector<int> count(26, 0);
        stack<char> stack;
        string res = "";
        for (int i = 0; i < n; i++){
            count[s[i] - 'a']++;
            stack.push(s[i]);
            if (i < n - 1){
                while (!stack.empty() && stack.top() <= min_char[i + 1]){
                    res += stack.top();
                    stack.pop();
                }
            }
        }
        while (!stack.empty()){
            res += stack.top();
            stack.pop();
        }
        return res;
    }
};