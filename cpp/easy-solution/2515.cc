/*
2515. Shortest Distance to a Target String in Circular Array
    You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.
    Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.
    Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.
    Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.

    Example :
    Input: words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1
    Output: 1
    Explanation: We start from index 1 and can reach "hello" by
    - moving 3 units to the right to reach index 4.
    - moving 2 units to the left to reach index 4.
    - moving 4 units to the right to reach index 0.
    - moving 1 unit to the left to reach index 0.
    The shortest distance to reach "hello" is 1.
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();          
        int ans = n;                
        for (int i = 0; i < n; i++) { 
            if (words[i] == target) { 
                int Distance = abs(i - startIndex);
                ans = min(ans, min(n - Distance, Distance)); 
            }
        }
        return ans == n ? -1 : ans;   
    }
};