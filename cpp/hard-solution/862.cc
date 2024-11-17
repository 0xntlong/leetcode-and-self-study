/*
862. Shortest Subarray with Sum at Least K
    Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
    A subarray is a contiguous part of an array.

    Example :
    Input: nums = [1], k = 1
    Output: 1
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }
        deque<int> dq;
        int Minlength = INT_MAX;
        for (int i = 0; i <= n; i++){
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k){
                Minlength = min(Minlength, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return Minlength == INT_MAX ? -1 : Minlength;
    }
};