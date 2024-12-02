/*
1869. Longer Contiguous Segments of Ones than Zeros
    Given a binary string s, return true if the longest contiguous segment of 1's is strictly longer than the longest contiguous segment of 0's in s, or return false otherwise.
    For example, in s = "110100010" the longest continuous segment of 1s has length 2, and the longest continuous segment of 0s has length 3.
    Note that if there are no 0's, then the longest continuous segment of 0's is considered to have a length 0. The same applies if there is no 1's.

    Example :
    Input: s = "1101"
    Output: true
    Explanation:
    The longest contiguous segment of 1s has length 2: "1101"
    The longest contiguous segment of 0s has length 1: "1101"
    The segment of 1s is longer, so return true.
*/

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool checkZeroOnes(string s) {
        int count1 = 0;
        int count0 = 0;
        int freq1 = 0;
        int freq0 = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '1'){
                count1++;
                freq1 = max(freq1, count1);
                count0 = 0;
            }
            if (s[i] == '0'){
                count0++;
                freq0 = max(freq0, count0);
                count1 = 0;
            }
        }
        return freq1 > freq0;
    }
};