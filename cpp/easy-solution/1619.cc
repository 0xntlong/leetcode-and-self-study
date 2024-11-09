/*
1619. Mean of Array After Removing Some Elements
    Given an integer array arr, return the mean of the remaining integers after removing the smallest 5% and the largest 5% of the elements.
    Answers within 10-5 of the actual answer will be considered accepted.

    Example :
    Input: arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
    Output: 2.00000
    Explanation: After erasing the minimum and the maximum values of this array, all elements are equal to 2, so the mean is 2.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int percent_5 = (arr.size()*5)/100;
        int sum = 0, cnt = 0;
        for (int i = percent_5; i < arr.size() - percent_5; i++){
            sum += arr.at(i);
            cnt++;
        }
        return (((double)sum)/cnt);
    }
};