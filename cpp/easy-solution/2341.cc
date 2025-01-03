/*
2341. Maxumum Number of Pairs in Array
    You are given a 0-indexed integer array nums. In one operation, you may do the following:
    Choose two integers in nums that are equal.
    Remove both integers from nums, forming a pair.
    The operation is done on nums as many times as possible.
    Return a 0-indexed integer array answer of size 2 where answer[0] is the number of pairs that are formed and answer[1] is the number of leftover integers in nums after doing the operation as many times as possible.

    Example :
    Input: nums = [1,3,2,1,3,2,2]
    Output: [3,1]
    Explanation:
    Form a pair with nums[0] and nums[3] and remove them from nums. Now, nums = [3,2,3,2,2].
    Form a pair with nums[0] and nums[2] and remove them from nums. Now, nums = [2,2,2].
    Form a pair with nums[0] and nums[1] and remove them from nums. Now, nums = [2].
    No more pairs can be formed. A total of 3 pairs have been formed, and there is 1 number leftover in nums.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_set<int> pair;
        int count = 0;
        for (int num : nums){
            if (pair.count(num)){
                pair.erase(num);
                count++;
            } else {
                pair.insert(num);
            }
        }
        return {count, (int)pair.size()};
    }
};