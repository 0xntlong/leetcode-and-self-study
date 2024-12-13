/*
2593. Find Score of an Array After Marking All Elemnents
    You are given an array nums consisting of positive integers.
    Starting with score = 0, apply the following algorithm:
    Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
    Add the value of the chosen integer to score.
    Mark the chosen element and its two adjacent elements if they exist.
    Repeat until all the array elements are marked.
    Return the score you get after applying the above algorithm.

    Example :
    Input: nums = [2,1,3,4,5,2]
    Output: 7
    Explanation: We mark the elements as follows:
    - 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
    - 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
    - 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
    Our score is 1 + 2 + 4 = 7.
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>>Sorted(n);
        for (int i = 0; i < n; i++){
            Sorted[i] = {nums[i], i};
        }
        sort(Sorted.begin(), Sorted.end());
        long long res = 0; 
        for (int i = 0; i < n; i++){
            int num = Sorted[i].first;
            int idx = Sorted[i].second;
            if (nums[idx] != -1){
                res += num;
                nums[idx] = -1;
                if (idx > 0){
                    nums[idx - 1] = -1;
                }
                if (idx < n - 1){
                    nums[idx + 1] = -1;
                }
            }
        }
        return res;
    }
};