/*
2601. Prime Subsraction Operation
    You are given a 0-indexed integer array nums of length n.
    You can perform the following operation as many times as you want:
    Pick an index i that you have not picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
    Return true if you can make nums a strictly increasing array using the above operation and false otherwise.
    A strictly increasing array is an array whose each element is strictly greater than its preceding element.

    Example :
    Input: nums = [4,9,6,10]
    Output: true
    Explanation: In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
    In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
    After the second operation, nums is sorted in strictly increasing order, so the answer is true.
*/

#include <vector>
#include <cmath>
using namespace std;
class Solution {
private:
    int MaxElement(vector<int> & nums){
        int max = - 1;
        for (int num : nums){
            if (num > max){
                max = num;
            }
        }
        return max;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = MaxElement(nums);
        vector<bool> marked(maxElement + 1, true);
        marked[1] = false;
        for (int i = 2; i <= sqrt(maxElement + 1); i++){
            if(marked[i]){
                for (int j = i * i; j <= maxElement; j += i){
                    marked[j] = false;
                }
            }
        }
        int currVal = 1;
        int i = 0;
        while( i < nums.size()){
            int diff = nums[i] - currVal;
            if (diff < 0){
                return false;
            }
            if(marked[diff] == true || diff == 0){
                i++;
                currVal++;
            } else {
                currVal++;
            }
        }
        return true;
    }
};