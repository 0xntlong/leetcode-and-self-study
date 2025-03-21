/*
2379. Minimum Recolors to Get K Consecutive Black Blocks
    You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.
    You are also given an integer k, which is the desired number of consecutive black blocks.
    In one operation, you can recolor a white block such that it becomes a black block.
    Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

    Example :
    Input: blocks = "WBBWWBBWBW", k = 7
    Output: 3
    Explanation:
    One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
    so that blocks = "BBBBBBBWBW". 
    It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
    Therefore, we return 3.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int minColor = k;
        int curr = 0;
        for (int i = 0; i < k; i++){
            if (blocks[i] == 'W'){
                curr++;
            }
        }
        minColor = curr;
        for (int i = k; i < n; i++){
            if (blocks[i - k] == 'W'){
                curr--;
            } if (blocks[i] == 'W'){
                curr++;
            }
            minColor = min(minColor, curr);
        }
        return minColor;
    }
};