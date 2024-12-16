/*
2099. Find Subsequence of Length K With the Largest Sum
    You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
    Return any such subsequence as an integer array of length k.
    A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

    Example :
    Input: nums = [2,1,3,3], k = 2
    Output: [3,3]
    Explanation:
    The subsequence has the largest sum of 3 + 3 = 6.
*/

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> minHeap;
        vector<int> freq;
        for (int i = 0; i < nums.size(); i++){
            minHeap.push_back({nums[i], i});
            push_heap(minHeap.begin(), minHeap.end(), greater<pair<int, int>>());
            if (minHeap.size() > k){
                pop_heap(minHeap.begin(), minHeap.end(), greater<pair<int, int>>());
                minHeap.pop_back();
            }
        }
        sort(minHeap.begin(), minHeap.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        });
        for (auto& p : minHeap){
            freq.push_back(p.first);
        }
        return freq;
    }
};