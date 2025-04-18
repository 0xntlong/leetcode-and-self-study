/*
38. Count and Say
    The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
    countAndSay(1) = "1"
    countAndSay(n) is the run-length encoding of countAndSay(n - 1).
    Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".
    Given a positive integer n, return the nth element of the count-and-say sequence.

    Example 1:
    Input: n = 4
    Output: "1211"
    Explanation:
    countAndSay(1) = "1"
    countAndSay(2) = RLE of "1" = "11"
    countAndSay(3) = RLE of "11" = "21"
    countAndSay(4) = RLE of "21" = "1211"
*/

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
    public:
        using info = pair<int, char>;
        static string str(const vector<info>& sequence){
            string ans;
            ans.reserve(sequence.size() << 1);
            for (auto& [freq, digit] : sequence){
                ans += to_string(freq);
                ans.push_back(digit);
            }
            return ans;
        }
        string countAndSay(int n) {
            if (n == 1)
                return "1";
            vector<info> sequence={{1, '1'}};
            string s1 = str(sequence);
            for (int i = 3; i <= n; i++){
                const int len = s1.size();
                char c = s1[0];
                sequence = {{1, c}};
                for (int i = 1; i < len; i++){
                    if (s1[i] == c){
                        sequence.back().first++;
                    } else {
                        sequence.emplace_back(1, s1[i]);
                        c = s1[i];
                    }
                }
                s1 = str(sequence);
            }
            return s1;
        }
    };