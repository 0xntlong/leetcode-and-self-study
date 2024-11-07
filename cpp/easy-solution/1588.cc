/*
1588. Sum of All Odd Length Subarrays
    Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.
    A subarray is a contiguous subsequence of the array.

    Example :
    Input: arr = [1,4,2,5,3]
    Output: 58
    Explanation: The odd-length subarrays of arr and their sums are:
    [1] = 1
    [4] = 4
    [2] = 2
    [5] = 5
    [3] = 3
    [1,4,2] = 7
    [4,2,5] = 11
    [2,5,3] = 10
    [1,4,2,5,3] = 15
    If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
*/

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++){
            int temp = 0;
            for (int j = i; j < arr.size(); j++){
                temp += arr[j];
                if (abs(i - j) % 2 != 0)
                    continue;
                sum += temp;
            }
        }
        return sum;
    }
};