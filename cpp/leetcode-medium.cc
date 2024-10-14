/*
This file is a minimal set of MEDIUM solutions to leetcode problems in C++.
No algorithms or reasoning are provided to save space.
For more details, readers are suggested to explore on their own or search on Threads platform : leetcodedaybyday . Thanks for reading.
*/

#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    /*
    2530. Maximal Score After Applying K Operations
    You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
    In one operation:
    choose an index i such that 0 <= i < nums.length,
    increase your score by nums[i], and
    replace nums[i] with ceil(nums[i] / 3).
    Return the maximum possible score you can attain after applying exactly k operations.
    The ceiling function ceil(val) is the least integer greater than or equal to val.

    Example:
    Input: nums = [10,10,10,10,10], k = 5
    Output: 50
    Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.
    */
    int maxKelements(vector<int>& nums, int k) {
        int res = 0;
        priority_queue<int> max_heap(nums.begin(), nums.end());
        while (k--) {
            int n = max_heap.top();
            max_heap.pop();
            res += n;
            max_heap.push(ceil(n / 3.0));
        }
        return res;
    }
};