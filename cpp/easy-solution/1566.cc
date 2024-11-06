/*
1566. Detect Pattern of Length M Repeated K or More Times
    Given an array of positive integers arr, find a pattern of length m that is repeated k or more times.
    A pattern is a subarray (consecutive sub-sequence) that consists of one or more values, repeated multiple times consecutively without overlapping. A pattern is defined by its length and the number of repetitions.
    Return true if there exists a pattern of length m that is repeated k or more times, otherwise return false.

    Example :
    Input: arr = [1,2,4,4,4,4], m = 1, k = 3
    Output: true
    Explanation: The pattern (4) of length 1 is repeated 4 consecutive times. Notice that pattern can be repeated k or more times but not less.
*/

#include <vector>
using namespace std;
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int count = 0;
        for (int i = 0; i + m < arr.size(); i++){
            if (arr[i] != arr[i + m]){
                count = 0;
            }
            count += (arr[i] == arr[i + m]);
            if (count == (k - 1)*m)
                return true;
        }
        return false;
    }
};