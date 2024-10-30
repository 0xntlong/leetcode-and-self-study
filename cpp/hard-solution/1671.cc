/*
1671. Minimum Number of Removals to Make Mountain Array
    You may recall that an array arr is a mountain array if and only if:
    arr.length >= 3
    There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
    arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
    Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.

    Example :
    Input: nums = [1,3,1]
    Output: 0
    Explanation: The array itself is a mountain array so we do not need to remove any elements.
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size();
        vector<int> LIS(N, 1);
        vector<int> smallest;
        for (int i = 0; i < N; i++){
            auto j = lower_bound(smallest.begin(), smallest.end(), nums[i]);
            int idx = j - smallest.begin();
            if ( j == smallest.end())
                smallest.push_back(nums[i]);
            else
                *j = nums[i];
            LIS[i] = idx + 1;
        }
        vector<int> LDS(N, 1);
        smallest.clear();
        for (int i = N - 1; i >= 0; i--){
            auto j = lower_bound(smallest.begin(), smallest.end(), nums[i]);
            int idx = j - smallest.begin();
            if (j == smallest.end())
                smallest.push_back(nums[i]);
            else 
                *j = nums[i];
            LDS[i] = idx + 1;
        }
        int minimum = N;
        for ( int i = 0; i < N -1; i++){
            if (LIS[i] > 1 && LDS[i] > 1){
                minimum = min(minimum, N - LIS[i] - LDS[i] + 1);
            }
        }
        return minimum;
    }
};