/*
1405. Longest Happy String
    A string s is called happy if it satisfies the following conditions:
    s only contains the letters 'a', 'b', and 'c'.
    s does not contain any of "aaa", "bbb", or "ccc" as a substring.
    s contains at most a occurrences of the letter 'a'.
    s contains at most b occurrences of the letter 'b'.
    s contains at most c occurrences of the letter 'c'.
    Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
    A substring is a contiguous sequence of characters within a string.
    
    Example :
    Input: a = 1, b = 1, c = 7
    Output: "ccaccbcc"
    Explanation: "ccbccacc" would also be a correct answer.
*/

#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        while (!pq.empty()){
            auto[count1, char1] = pq.top();
            pq.pop();
            if (res.size() >= 2 && res[res.size() - 1] == char1 && res[res.size() -2] == char1){
                if (pq.empty())
                    break;
                auto [count2, char2] = pq.top();
                pq.pop();
                res += char2;
                count2--;
                if (count2 > 0) pq.push({count2, char2});
                pq.push({count1, char1});
            } else {
                res += char1;
                count1--;
                if (count1 > 0) pq.push({count1, char1});
            }
        }
        return res;
    }
};