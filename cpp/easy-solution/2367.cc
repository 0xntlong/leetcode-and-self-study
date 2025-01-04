/*
2367. Number of Arithmetic Triplets
    You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:
    i < j < k,
    nums[j] - nums[i] == diff, and
    nums[k] - nums[j] == diff.
    Return the number of unique arithmetic triplets.

    Example :
    Input: nums = [0,1,4,6,7,10], diff = 3
    Output: 2
    Explanation:
    (1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
    (2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++){
            int j = i + 1;
            int k = j + 1;
            while (j < n && k < n){
                if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff){
                    res++;
                    j++;
                    k++;
                } else if (nums[j] - nums[i] < diff){
                    j++;
                } else if (nums[k] - nums[j] < diff){
                    k++;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};